//Vallery Salomon
//EEGR 409 C Programming Applications
//Project 2.2

#include <stdio.h>
#include <sys/timeb.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "display.h"
#include "project1.h"


#define MIN_SEP_HIGH 10			//minimum separation at high speed
#define MIN_SEP_LOW 7			//minimum separation at low speed


int lastUpdateTime = 0;
int lanePosCircle[4][4] = { {220, 117, 280, 117},
						  {280, 133, 220, 133},
						  {257, 95, 257, 155},
						  {243, 155, 243, 95} };			//lane positions, x, y of start of intersection, and x, y of end of intersection

//define properties of car
double carPos[NUM_CARS][2] = { 0 };		// x, y position of all cars
double carVel[NUM_CARS] = { 0 };		// velocity of all cars
double carAcc[NUM_CARS] = { 0 };		// acceleration of all cars
double carMaxSpeed[NUM_CARS] = { 0 };	// max speed
double carDecelRate[NUM_CARS] = { 0 };  // car deceleration rate
double carAccelRate[NUM_CARS] = { 0 };	// car acceleration rate
double carStopPos[NUM_CARS] = { 0 };	// where car will stop if breaks are applied 
double carSlope[NUM_CARS] = { 0 };		// The slope at which to reach next direction
int carDir[NUM_CARS] = { 0 };			// car direction on track
int carReachingGoal[NUM_CARS] = { 0 };	// car is reaching goal
int carGoalReached[NUM_CARS] = { 0 };	// car has reached goal
int carTimeSinceGoal[NUM_CARS] = { 0 };	// amount of since since car reached goal
int carInIntersection[NUM_CARS] = { 0 }; // car is in intersection
int carPassedInter[NUM_CARS] = { 0 };	// car is passed intersection
int carStarted[NUM_CARS] = { 0 };		// car is instantiated in simulation
int carTimeAtIntersection[NUM_CARS] = { 0 };	// time car reached intersection
int carNextDir[NUM_CARS] = { 0 };	// next direction of car
int timeSinceLastCar = 0;	// time since last car started
int carCount = 0;	// number of cars through intersection
int timeOfFirstCarInInter = 0;	// time of first car in intersection
int timeOfLastCarInInter = 0;	// time of last car in intersection 

//Initialize cars
void InitCars()
{

	int i = 0;

	srand(time(NULL));

	for (i = 0; i < NUM_CARS; i++)
	{
		carAcc[i] = (3 * (rand() / (float)RAND_MAX)) + 1;
		carAccelRate[i] = carAcc[i];
		carMaxSpeed[i] = (20 * (rand() / (float)RAND_MAX)) + 20;
		carDecelRate[i] = -5;
		carVel[i] = 0;
		carDir[i] = rand() % 4;
		//printf("%i \n", carDir[i]);
		if (carDir == 0)
		{
			carPos[i][0] = -10;
			carPos[i][1] = lanePosCircle[0][1];
		}
		else if (carDir[i] == 1)
		{
			carPos[i][0] = 510;
			carPos[i][1] = lanePosCirlce[1][1];
		}
		else if (carDir[i] == 2)
		{
			carPos[i][1] = -10;
			carPos[i][0] = lanePosCircle[2][0];
		}
		else if (carDir[i] == 3)
		{
			carPos[i][1] = 260;
			carPos[i][0] = lanePosCircle[3][0];
		}
	}
}

// Display Statistics
void DisplayStats()
{
	int i;
	for (i = 0; i < 79; i++) printf("%c", 8);
	printf("Total number of vehicles: %d  \n", NUM_CARS);
	printf("Average number of vehicles per sec: %3.2f\n", (timeOfLastCarInInter - timeOfFirstCarInInter) / (float)NUM_CARS / 1000);
}

// Set vehicles acceleration based on proximity to leading vehicle
void EnsureMinSep(double *carPos, double *pCarPos, double *carVel, double *carAcc, double *carAccRate, double *carDecRate, int dir)
{
	if ((dir == 1 ? *pCarPos : *carPos - *pCarPos) < (*carVel > 5 ? MIN_SEP_HIGH : MIN_SEP_LOW)) *carAcc = *carDecRate;
	else *carAcc = *carAccRate;
}

//Determine vehice positions based on dynamics
void UpdatePositions()
{
	double timeDelta;
	double dist;
	int carIndex;
	int dir = 1;
	int orientation = 0;
	int i, closestCar, closestDist, t;
	int sameDir = 0;
	static int sameDirDone = 0;
	static int totalTime = 0;
	int newDir;

	//Get current system time
	struct timeb tp;
	ftime(&tp);

	//Determine how much time has passed since last update
	if (lastUpdateTime != 0) timeDelta = tp.millitm - lastUpdateTime;
	else timeDelta = 0;
	if (timeDelta < 0) timeDelta = 1000 + timeDelta;
	timeSinceLastCar += timeDelta;
	totalTime += timeDelta;
	timeDelta /= 1000;
	lastUpdateTime = tp.millitm;

	//Process each car entity
	for (carIndex = 0; carIndex < NUM_CARS; carIndex++)
	{
		//Instantiate a car
		if (timeSinceLastCar > (rand() % 2000) + 1000 && !carStarted[carIndex])
		{
			carStarted[carIndex] = 1;
			timeSinceLastCar = 0;
		}

		//Advance time since goal reached 
		if (carGoalReached[carIndex]) carTimeSinceGoal[carIndex] += timeDelta * 1000;

		//Restart from the first car if car not visible to make sure proper car sequencing occurs
		if (carVel[carIndex] > carMaxSpeed[carIndex] && carAcc[carIndex] > 0) carAcc[carIndex] = 0;
		carVel[carIndex] += carAcc[carIndex] * timeDelta;
		if (carVel[carIndex] < 0) carVel[carIndex] = 0;

		//Set car direction modifiers
		if (carDir[carIndex] == 1 || carDir[carIndex] == 3) dir = -1;
		else dir = 1;
		if (carDir[carIndex] >= 2) orientation = 1;
		else orientation = 0;

		//Calculate where vehicle will stop if breaks are applied now
		carStopPos[carIndex] = carPos[carIndex][orientation] + dir * (-(pow(carVel[carIndex], 2) / carDecelRate[carIndex]) + (0.5 * pow(carVel[carIndex], 2) / carDecelRate[carIndex]));

		//Check if too close to other behicles (if stop distance violates minimum separation)
		if (!carGoalReached[carIndex])
		{
			//Find closest car in the same direction
			closestDist = 500;
			for (i = 0; i < NUM_CARS; i++)
			{
				t = dir * (carPos[i][orientation] - carPos[carIndex][orientation]);
				if (i != carIndex && carDir[i] == carDir[carIndex] && closestDist > t && t > 0)
					//else carAcc[carIndex] = carAccelRate[carIndex];
					closestDist = t;
					closestCar = i;
			}
		}
		if (closestDist != 500) EnsureMinSep(&carStopPos[carIndex], &carStopPos[closestCar], &carVel[carIndex], &carAcc[carIndex], &carAccelRate[carIndex], &carDecelRate[carIndex], dir);
	}

	//Determine if car should start deceleration because goal has almost been reached
	if (!carGoalReached[carIndex])
	{
		if ((carDir[carIndex] == 0 && carStopPos[carIndex] >= lanePosCircle[0][0])
			|| (carDir[carIndex] == 1 && carStopPos[carIndex] <= lanePosCircle[1][0])
			|| (carDir[carIndex] == 2 && carStopPos[carIndex] >= lanePosCircle[2][1])
			|| (carDir[carIndex] == 3 && carStopPos[carIndex] <= lanePosCircle[3][1]))
		{
			carReachingGoal[carIndex] = 1;
			carAcc[carIndex] = carDecelRate[carIndex];
		}
	}

	//Chech if at intersection
	if (carVel[carIndex] <= 0 && carReachingGoal[carIndex])
	{
		carGoalReached[carIndex] = 1;
		carReachingGoal[carIndex] = 0;
		carAcc[carIndex] = 0;
		carVel[carIndex] = 0;
		carTimeAtIntersection[carIndex] = totalTime;
		if (!timeOfFirstCarInInter) timeOfFirstCarInInter = totalTime;

		//Determine new direction & calculate slope to get ther
		newDir = rand() % 4;
		if ((carDir[carIndex] == 0 && newDir == 1) || (carDir[carIndex] == 1 && newDir == 0) || (carDir[carIndex] == 2 && newDir == 3) || (carDir[carIndex] == 3 && newDir == 2)) newDir = 3 - carDir[carIndex];
		carSlope[carIndex] = (lanePosCircle[newDir][3] - lanePosCircle[carDir[carIndex]][1]) / ((float)(lanePosCircle[newDir][2] - lanePosCircle[carDir[carIndex]][0]));
		carNextDir[carIndex] = newDir;
	}

	//Move Car into intersection in proper order only if no other car is in intersction
	if (carGoalReached[carIndex] && !carInIntersection[carIndex] && !carPassedInter[carIndex] && carTimeSinceGoal[carIndex] > 1000 + (rand() % 4000))
	{
		sameDir = 0;
		for (i = 0; i < NUM_CARS; i++) if (carInIntersection[i] && !carPassedInter[i]) break;

		if (i == NUM_CARS || sameDir)
		{
			for (i = 0; i < NUM_CARS; i++) if (carTimeAtIntersection[carIndex] > carTimeAtIntersection[i] && carGoalReached[i] && !carPassedInter[i]) break;
			if (i == NUM_CARS || (sameDir && !sameDirDone))
			{
				carInIntersection[carIndex] = 1;
				carAcc[carIndex] = carAccelRate[carIndex];
			}
		}
	}

	//Car has moved beyonnd intersection
	if (carInIntersection[carIndex] && !carPassedInter[carIndex] && ((carNextDir[carIndex] == 0 && carPos[carIndex][0] > lanePos[0][2])
		|| (carNextDir[carIndex] == 1 && carPos[carIndex][0] < lanePosCircle[1][2])
		|| (carNextDir[carIndex] == 2 && carPos[carIndex][1] > lanePosCircle[2][3])
		|| (carNextDir[carIndex] == 3 && carPos[carIndex][1] < lanePosCircle[3][3])))
	{
		carPassedInter[carIndex] = 1;
		carDir[carIndex] = carNextDir[carIndex];
		carCount++;
		for (i = 0; i < 79; i++) printf("%c", 8);
		printf("Number f cars passed intersection: %d", carCount);
		if (carCount == NUM_CARS)
		{
			timeOfLastCarInInter = totalTime;
			DisplayStats();
		}
	}

	//Determine distance traveled
	dist = timeDelta * carVel[carIndex];

	//Update positions based on distance traveled
	if (dist > 0)
	{
		carPos[carIndex][orientation] += dir*dist;
		if (carInIntersection[carIndex] && !carPassedInter[carIndex])
		{
			//Treat moving up and down (direction 2 and 3) as special cases because of divide my zero error
			if (!((carDir[carIndex] == 2 && carNextDir[carIndex] == 2)
				|| (carDir[carIndex] == 3 && carNextDir[carIndex] == 3)))
				carPos[carIndex][1 - orientation] = carPos[carIndex][1 - orientation] + (carSlope[carIndex] * (dir*dist));
		}
	}
}

void UpdateSim()
{
	int i;
	UpdatePositions();

	for (i = 0; i < NUM_CARS; i++)
		UpdateSymbol(i, carPos[i][0], carPos[i][1]);
}

int main(int argc, char **argv)
{
	printf("		Traffic Simulator for Flow Efficiency Quantification\n");
	printf("		----------------------------------------------------\n\n");

	InitCars();

	ShowDisplay(1);
	SetMap(1);
}
