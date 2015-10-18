#ifndef screen2_h
#define screen2_h

#include "../demo.h"
#include <stdlib.h>

u32 S2x1;
u32 S2y2;

void Screen2_Init()
{
	S2x1 = 0;
	S2y2 = 0;
}

void Screen2_PreFrameCalc() {}
void Screen2_Cleanup()
{
	Plot(120, 80,        FromRGB( 0,  0,  0));
	Plot(119 - S2x1, 80, FromRGB( 0,  0,  0));
	Plot(120, 79 - S2y2, FromRGB( 0,  0,  0));
}

void Screen2_Frame(u32 localFrame)
{
	Plot(120, 80,        FromRGB( 0,  0,  0));
	Plot(119 - S2x1, 80, FromRGB( 0,  0,  0));
	Plot(120, 79 - S2y2, FromRGB( 0,  0,  0));

	S2x1 = (S2x1 + 1) % 60;
	S2y2 = (S2y2 + 2) % 60;

	Plot(120, 80,        FromRGB(31,  0, 31));
	Plot(119 - S2x1, 80, FromRGB( 0, 31, 31));
	Plot(120, 79 - S2y2, FromRGB(31, 31,  0));
}

void Screen2_PostFrameCalc()
{

}

Screen* Screen2_Create()
{
	Screen* s = (Screen*)malloc(sizeof(Screen));

	s->init          = Screen2_Init;
	s->preFrameCalc  = Screen2_PreFrameCalc;
	s->frame         = Screen2_Frame;
	s->postFrameCalc = Screen2_PostFrameCalc;
	s->cleanup       = Screen2_Cleanup;
	s->frameEnd      = 360;

	return s;
}

#endif /* screen1_h */

