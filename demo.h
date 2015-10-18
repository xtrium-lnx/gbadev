#ifndef __DEMO_H_INCLUDED__
#define __DEMO_H_INCLUDED__

#include "gba.h"

typedef struct Screen_
{
	void(*init)();
	void(*preFrameCalc)();
	void(*frame)(u32);
	void(*postFrameCalc)();
	void(*cleanup)();

	u32 frameEnd;
} Screen;

#define MAX_SCREENS 32
typedef Screen* ScreenList[MAX_SCREENS];

ScreenList screenList;
u32 currentScreen;
u32 countScreen;

void Demo_Init()
{
	currentScreen = 0;
	countScreen   = 0;

	int i;
	for(i = 0; i < MAX_SCREENS; ++i)
		screenList[i] = (Screen*)0;
};

void Demo_AddScreen(Screen* s)
{
	if(countScreen >= MAX_SCREENS)
		return;
	
	screenList[countScreen++] = s;
}

inline void Demo_DoFrame(u32 frameCount)
{
	if(currentScreen >= MAX_SCREENS || currentScreen >= countScreen)
		return;

	u32 lastCount = 0;
	if(currentScreen)
		lastCount = screenList[currentScreen - 1]->frameEnd - 1;

	Screen* s = screenList[currentScreen];
	s->preFrameCalc();
	s->frame(frameCount - lastCount);
	s->postFrameCalc();
}

inline void Demo_DoScreenCheck(u32 frameCount)
{
	if(currentScreen >= MAX_SCREENS || currentScreen >= countScreen)
		return;

	if(frameCount >= screenList[currentScreen]->frameEnd)
	{
		screenList[currentScreen]->cleanup();

		++currentScreen;
		if(currentScreen < MAX_SCREENS && currentScreen < countScreen)
			screenList[currentScreen]->init();
	}
}

#endif /* __DEMO_H_INCLUDED__ */

