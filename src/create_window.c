#include "UI.h"

WINDOW *cwin(int height, int width, int starty, int startx)
{
	WINDOW *win = newwin(height, width, starty, startx);
	draw_box(win, height, width, starty, startx);
	wrefresh(win);
	return win;
}
