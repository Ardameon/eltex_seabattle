#include "UI.h"

void draw_box(WINDOW *win, int h, int w, int sy, int sx)
{
	h -= 1;
	w -= 1;
	/*mvaddch(sy, sx, ACS_PLUS);*/
	/*mvaddch(sy, sx + w, ACS_PLUS);*/
	/*mvaddch(sy + h, sx, ACS_LLCORNER);*/
	/*mvaddch(sy + h, sx + w, ACS_LRCORNER);*/
	mvhline(sy, sx + 1, ACS_HLINE, w - 1);
	mvhline(sy + h, sx + 1, ACS_HLINE, w - 1);
	mvvline(sy + 1, sx, ACS_VLINE, h - 1);
	mvvline(sy + 1, sx + w, ACS_VLINE, h - 1);
}
