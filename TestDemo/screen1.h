#ifndef screen1_h
#define screen1_h

#include "../demo.h"
#include <stdlib.h>

u32 S1x1;
u32 S1y2;

void Screen1_Init()
{
	S1x1 = 0;
	S1y2 = 0;
}

void Screen1_PreFrameCalc() {}
void Screen1_Cleanup()
{
	Plot(120, 80,        FromRGB( 0,  0,  0));
	Plot(121 + S1x1, 80, FromRGB( 0,  0,  0));
	Plot(120, 81 + S1y2, FromRGB( 0,  0,  0));
}

void Screen1_Frame(u32 localFrame)
{
	Plot(120, 80,        FromRGB( 0,  0,  0));
	Plot(121 + S1x1, 80, FromRGB( 0,  0,  0));
	Plot(120, 81 + S1y2, FromRGB( 0,  0,  0));

	S1x1 = (S1x1 + 1) % 60;
	S1y2 = (S1y2 + 2) % 60;

	Plot(120, 80,        FromRGB(31,  0,  0));
	Plot(121 + S1x1, 80, FromRGB( 0, 31,  0));
	Plot(120, 81 + S1y2, FromRGB(31, 31, 31));
}

void Screen1_PostFrameCalc()
{

}

Screen* Screen1_Create()
{
	Screen* s = (Screen*)malloc(sizeof(Screen));

	s->init          = Screen1_Init;
	s->preFrameCalc  = Screen1_PreFrameCalc;
	s->frame         = Screen1_Frame;
	s->postFrameCalc = Screen1_PostFrameCalc;
	s->cleanup       = Screen1_Cleanup;
	s->frameEnd      = 180;

	return s;
}

#endif /* screen1_h */

