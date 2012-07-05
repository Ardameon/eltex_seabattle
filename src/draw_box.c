#include "UI.h"

void draw_box(WINDOW *win, int h, int w, int sy, int sx)
{
	h -= 1;
	w -= 1;
	mvhline(sy, sx + 1, ACS_HLINE, w - 1);
	mvhline(sy + h, sx + 1, ACS_HLINE, w - 1);
	mvvline(sy + 1, sx, ACS_VLINE, h - 1);
	mvvline(sy + 1, sx + w, ACS_VLINE, h - 1);
}
