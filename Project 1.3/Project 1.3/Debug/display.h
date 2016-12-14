#ifndef __display_h__
#define __display_h__

#define IMG_WIDTH  500
#define IMG_HEIGHT 250

//extern void Init_LED_Array(int argc, char **argv,void (__cdecl *func)());
extern void ShowDisplay();
extern void display();
extern void UpdateSymbol(int symbolIndex, double x, double y);

#endif