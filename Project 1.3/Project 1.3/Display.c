#include <Windows.h>
#include <gl/gl.h>
#include <math.h>
#include <stdio.h>
#include "glut.h"
#include "display.h"
#include "project1.h"

float symbolPos[NUM_CARS][2];			// Position of symbols
float showSymbol[NUM_CARS] = { 0 };		// True if symbol should be rendered
int mapID = 0;							// Map to place under each symbol
float colors[64][3] = { 0 };			// Colors for each symbol

void init()
{
	float LightAmbient[] = { 0.3f, 0.3f, 0.3f, 1.0f };		// Ambient Light Values
	float LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };		// Diffuse Light Values
	float LightPosition[] = { 25.0f, 25.0f, 15.0f, 1.0f };	// Light Position
	float LightSpecular[] = { 0.8f, 0.8f, 0.8f, 1.0f };	// Specular Light Values
	float LightPosition2[] = { 40.0f, 40.0f, 5.0f, 1.0f };// Light Position

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glEnable(GL_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// Create ambient light
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);			// Setup The Ambient Light

															// Create diffuse Light 1
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);			// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);		// Position The Light

															// Create specular light 2
	glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse);			// Setup The Diffuse Light
	glLightfv(GL_LIGHT2, GL_SPECULAR, LightSpecular);		// Setup The specular Light
	glLightfv(GL_LIGHT2, GL_POSITION, LightPosition2);		// Position The Light

															//glEnable(GL_COLOR_MATERIAL);							// Enable color material (blend polygon colors with lighting)
															//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

}

void ReshapeFunc(GLint width, GLint height)
{
	height = (height == 0 ? 1 : height);					// Prevent A Divide By Zero By

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(0, width / 10.0, 0, height / 10.0, -50, 50);			// Create orthographic viewing volume
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();
}

void display()
{
	GLUquadricObj *quadric;
	float specReflection[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	int i, j;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer

	glLoadIdentity();
	glLineWidth(4);

	int track1x = 235;
	int track2x = 265;
	int track3y = 140;
	int track4y = 110;

	// Create traffic circle
	if (mapID == 1)
	{
		track1x -= 10;
		track2x += 10;
		track3y += 10;
		track4y -= 10;

		int r = 30;
		glColor3f(1, 1, 0);
		int pause = 0;
		glBegin(GL_LINE_STRIP);
		{
			// Outer circle
			for (float theta = .5; theta < (2 * PI) - 0.5; theta += 0.05)
			{
				if (theta > .4 && !pause)
				{
					float x = (r * cos(theta)) + (IMG_WIDTH / 2.0);
					float y = (r * sin(theta)) + (IMG_HEIGHT / 2.0);
					glVertex2f(x / 5.0, y / 5.0);
				}
				if (((theta > 1.1 && theta < 2) || (theta > 2.6 && theta < 3.6) || (theta > 4.12 && theta < 5.2)) && !pause)
				{
					glEnd();
					pause = 1;
				}
				if (((theta > 2) || (theta > 3.6) || theta > 5.2) && pause)
				{
					glBegin(GL_LINE_STRIP);
					pause = 0;
				}

			}
			glEnd();

			// Inner circle
			r = 15;
			glColor3f(0, 1, 0);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(IMG_WIDTH / 2.0 / 5.0, IMG_HEIGHT / 2.0 / 5.0);
			for (float theta = 0; theta <= (2 * PI) + (2 * PI) / 20.0; theta += (2 * PI) / 20.0)
			{
				float x = (r * cos(theta)) + (IMG_WIDTH / 2.0);
				float y = (r * sin(theta)) + (IMG_HEIGHT / 2.0);
				glVertex2f(x / 5.0, y / 5.0);
			}
			glEnd();
			glColor3f(1, 1, 0);
			glBegin(GL_LINE_LOOP);
			for (float theta = 0; theta <= (2 * PI); theta += 0.3)
			{
				float x = (r * cos(theta)) + (IMG_WIDTH / 2.0);
				float y = (r * sin(theta)) + (IMG_HEIGHT / 2.0);
				glVertex2f(x / 5.0, y / 5.0);
			}
			glEnd();
		}
		glEnd();
	}

	// Display map
	glBegin(GL_LINES);
	{
		// Road outer lines 1
		glColor3f(1, 1, 0);
		glVertex2f(0, 110 / 5.0);
		glVertex2f(track1x / 5.0, 110 / 5.0);
		glVertex2f(0, 140 / 5.0);
		glVertex2f(track1x / 5.0, 140 / 5.0);

		// Road outer lines 2
		glColor3f(1, 1, 0);
		glVertex2f(track2x / 5.0, 110 / 5.0);
		glVertex2f(500 / 5.0, 110 / 5.0);
		glVertex2f(track2x / 5.0, 140 / 5.0);
		glVertex2f(500 / 5.0, 140 / 5.0);

		// Road outer lines 3
		glColor3f(1, 1, 0);
		glVertex2f(235 / 5.0, 250 / 5.0);
		glVertex2f(235 / 5.0, track3y / 5.0);
		glVertex2f(265 / 5.0, 250 / 5.0);
		glVertex2f(265 / 5.0, track3y / 5.0);

		// Road outer lines 4
		glColor3f(1, 1, 0);
		glVertex2f(235 / 5.0, track4y / 5.0);
		glVertex2f(235 / 5.0, 0 / 5.0);
		glVertex2f(265 / 5.0, track4y / 5.0);
		glVertex2f(265 / 5.0, 0 / 5.0);

		// Road center lines
		glColor3f(1, 1, 1);
		j = -1;
		for (i = 0; i < track1x - 10; i += 10)
		{
			j *= -1;
			if (j > 0)
			{
				glVertex2f(i / 5.0, 125 / 5.0);
				glVertex2f((i + 10) / 5.0, 125 / 5.0);
			}
		}

		// Road center lines 2
		glColor3f(1, 1, 1);
		j = -1;
		for (i = track2x + 10; i < 500; i += 10)
		{
			j *= -1;
			if (j > 0)
			{
				glVertex2f(i / 5.0, 125 / 5.0);
				glVertex2f((i + 10) / 5.0, 125 / 5.0);
			}
		}

		// Road center lines 3
		glColor3f(1, 1, 1);
		j = -1;
		for (i = track3y + 10; i < 250; i += 10)
		{
			j *= -1;
			if (j > 0)
			{
				glVertex2f(250 / 5.0, i / 5.0);
				glVertex2f(250 / 5.0, (i + 10) / 5.0);
			}
		}

		// Road center lines 4
		glColor3f(1, 1, 1);
		j = -1;
		for (i = 0; i < track4y - 10; i += 10)
		{
			j *= -1;
			if (j > 0)
			{
				glVertex2f(250 / 5.0, i / 5.0);
				glVertex2f(250 / 5.0, (i + 10) / 5.0);
			}
		}

		// ending lines 1
		int d = (mapID == 0 ? 0 : 5);
		glColor3f(1, 0.5, 0.5);
		glVertex2f((track1x - d) / 5.0, 112 / 5.0);
		glVertex2f((track1x - d) / 5.0, 125 / 5.0);

		//ending lines 2
		glColor3f(1, 0.5, 0.5);
		glVertex2f((track2x + d) / 5.0, 125 / 5.0);
		glVertex2f((track2x + d) / 5.0, 138 / 5.0);

		// ending lines 3
		glColor3f(1, 0.5, 0.5);
		glVertex2f(237 / 5.0, (track3y + d) / 5.0);
		glVertex2f(250 / 5.0, (track3y + d) / 5.0);

		// ending lines 4
		glVertex2f(250 / 5.0, (track4y - d) / 5.0);
		glVertex2f(263 / 5.0, (track4y - d) / 5.0);
	}
	glEnd();

	for (i = 0; i < NUM_CARS; i++)
	{
		if (showSymbol[i] && symbolPos[i][0] >= -5 && symbolPos[i][0] < IMG_WIDTH + 5 && symbolPos[i][1] >= -5 && symbolPos[i][1] < IMG_HEIGHT + 5)
		{
			glColor3f(colors[i][0], colors[i][1], colors[i][2]);
			glLoadIdentity();
			glTranslatef(symbolPos[i][0] / 5.0, symbolPos[i][1] / 5.0, 0);
			gluDisk(gluNewQuadric(), 0.3, 0.6, 16, 16);
		}
	}

	glutSwapBuffers();

}

void UpdateSymbol(int symbolIndex, double x, double y)
{
	if (symbolIndex < NUM_CARS)
	{
		symbolPos[symbolIndex][0] = x;
		symbolPos[symbolIndex][1] = y;
		showSymbol[symbolIndex] = 1;
	}
	display();
}

void ReadColors()
{
	FILE *fp = fopen("colors.txt", "r");
	int i = 0, j;

	/*	if (fp)
	{
	while (fscanf("%f,%f,%f", &colors[i][0], &colors[i][1], &colors[i][2]) != EOF) if (++i >= 64) break;
	fclose(fp);
	}
	else printf("Unable to open 'colors.txt' file\n");*/

	srand(1);
	for (i = 0; i < 64; i++)
		for (j = 0; j < 3; j++)
			colors[i][j] = (rand() / (float)RAND_MAX * 0.7) + 0.3;

}

// Set the map
void SetMap(int map)
{
	mapID = map;
}

//void Init_LED_Array(int argc, char **argv, void (__cdecl *func)())
void ShowDisplay(int map)
{
	int argc = 1;
	char *argv[] = { "project_1.exe" };
	mapID = map;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("EEGR 409: Project 1 - Traffic Simulation");
	glutReshapeFunc(ReshapeFunc);
	glutDisplayFunc(display);
	glutIdleFunc(UpdateSim);

	init();
	ReadColors();

	glutMainLoop();
}