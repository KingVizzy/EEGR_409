/*#ifndef __display_h__
#define __display_h__

#define IMG_WIDTH  500
#define IMG_HEIGHT 250
#define CIRCLE_RADIUS 22.5
#define PI 3.14159265359

#define CenterX 250
#define CenterY 125


//extern void Init_LED_Array(int argc, char **argv,void (__cdecl *func)());
extern void ShowDisplay(int map);
extern void SetMap(int map);
extern void display();
extern void UpdateSymbol(int symbolIndex, double x, double y);




#endif*/

#ifndef __display_h__
#define __display_h__

#define IMG_WIDTH  500
#define IMG_HEIGHT 250
#define CIRCLE_RADIUS 22.5
#define PI 3.14159265359
#define CenterX 250
#define CenterY 125

//extern void Init_LED_Array(int argc, char **argv,void (__cdecl *func)());
extern void ShowDisplay(int map);
extern void SetMap(int map);
extern void display();
extern void UpdateSymbol(int symbolIndex, double x, double y);
extern double proximity(double x1, double y1, double x2, double y2);
extern double xproximity(double x, double y, double distance);
extern void velocity(int index, double timecar);
extern void intersection(int index);
extern int inbetween(int index);
extern void changlanes(int index);


extern void velocityCircle(int index, double timecar);
extern void intersectionCircle(int index);
extern int inbetweenCircle(int index);
extern void changlanesCircle(int index);
extern void incircleline(int index, double timecar);

extern void GetConfigValue(char **settings, int j[15]);

#endif