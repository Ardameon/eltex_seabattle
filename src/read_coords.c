#include "UI.h"

int read_coords(int *retx, int *rety, const int height, const int width)
{
	int startx = 2;
	int starty = 1;
	int x = startx;
	int y = starty;
	int cw = CWIDTH - 1;
	int ch = CHEIGHT - 1;
	int c;
	int endx = cw * width - 2;
	int endy = ch * height - 1;

	mvprintw(LINES - 2, 1, "Select cell to shoot.\n");
	mvprintw(LINES - 1, 1, "Press F1 to exit.\n");

	move(y, x);
	refresh();

	while ((c = getch()) != KEY_F(1)) {
		switch(c) {
		case KEY_LEFT:
			x = (x <= startx) ? endx : x - cw;
			break;
		case KEY_RIGHT:
			x = (x >= endx) ? startx : x + cw;
			break;
		case KEY_UP:
			y = (y <= starty) ? endy : y - ch;
			break;
		case KEY_DOWN:
			y = (y >= endy) ? starty : y + ch;
			break;
		default:
			break;
		}
		move(y, x);
		refresh();
	}
	return 0;
}
