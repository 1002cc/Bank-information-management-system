#ifndef __SHOW__H
#define __SHOW__H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define DEFAULT_MODE "\e[0m" /*默认模式，不做任何处理*/
#define FONT_BLUE "\e[0;34m" /*默认，深蓝*/
#define CLEAR "\e[2J"        /*清除*/
#define BLINK "\e[5m"        /*闪烁*/
#define MOVERIGHT(y) printf("\033[%dC", (y))
#define MOVETO(x, y) printf("\033[%d;%dH", (x), (y))

extern void admin_menu(void);
extern void user_menu(void);
extern void frist_menu(void);
extern void change(void);
extern void progress_bar(void);
extern void Boot_animation(void);
extern void wiat(void);
#endif
