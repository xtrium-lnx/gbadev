#ifndef __GBA_H_INCLUDED__
#define __GBA_H_INCLUDED__

typedef unsigned char  u8;
typedef   signed char  s8;
typedef unsigned short u16;
typedef   signed short s16;
typedef unsigned int   u32;
typedef   signed int   s32;

typedef u16 COLOR;

#define MEM_IO        0x04000000
#define MEM_VRAM      0x06000000

#define REG_DISPCNT   *((volatile u32*)(MEM_IO + 0x0000))
#define REG_VCOUNT    *(volatile u16*)0x04000006

#define DCNT_MODE0    0x0000
#define DCNT_MODE1    0x0001
#define DCNT_MODE2    0x0002
#define DCNT_MODE3    0x0003
#define DCNT_MODE4    0x0004
#define DCNT_MODE5    0x0005

#define DCNT_BG0      0x0100
#define DCNT_BG1      0x0200
#define DCNT_BG2      0x0400
#define DCNT_BG3      0x0800
#define DCNT_OBJ      0x1000

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

#define VIDEO_MEMORY  ((u16*)MEM_VRAM)

//typedef COLOR Scanline[SCREEN_WIDTH]
//#define Pixels ((Scanline*)VIDEO_MEMORY)

#define COLOR_BLACK   0x0000
#define COLOR_RED     0x001F
#define COLOR_LIME    0x03E0
#define COLOR_YELLOW  0x03FF
#define COLOR_BLUE    0x7C00
#define COLOR_MAGENTA 0x7C1F
#define COLOR_CYAN    0x7FE0
#define COLOR_WHITE   0x7FFF

#define ScreenPixel(x,y) VIDEO_MEMORY[(y) * SCREEN_WIDTH + (x)]
#define Plot(x,y,c)      ScreenPixel(x,y) = c
#define FromRGB(r,g,b)   (r | (g << 5) | (b << 10))

#ifndef __thumb__
# pragma message("Compiling in THUMB mode")
# define swi_call(x) asm volatile("swi\t"#x ::: "r0", "r1", "r2", "r3")
#else
# pragma message("Compiling in NORMAL mode")
# define swi_call(x) asm volatile("swi\t"#x"<<16" ::: "r0", "r1", "r2", "r3")
#endif /* __thumb__ */

void Wait_VBlank()
{
	while(REG_VCOUNT >= 160); // Wait VDraw
	while(REG_VCOUNT  < 160); // Wait VBlank
}

#endif /* __GBA_H_INCLUDED__ */

