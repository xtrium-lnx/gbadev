#include "screen1.h"
#include "screen2.h"

inline void TestDemo_Init()
{
	Demo_Init();
	
	Demo_AddScreen(Screen1_Create());
	Demo_AddScreen(Screen2_Create());
}

/* ************************************************************************* */

u32 frameCount;

inline void DoConsoleInit()
{
	REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;
	frameCount = 0;
}

int main()
{
	DoConsoleInit();
	TestDemo_Init();

	do
	{
		Wait_VBlank();

		Demo_DoFrame(frameCount);
		Demo_DoScreenCheck(frameCount++);
	} while(1);

	return 0;
}
