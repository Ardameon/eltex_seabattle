#include "UI.h"

int read_coords(int *x, int *y, const int height)
{
	int wheight = 3;
	int wwidth = 30;
	WINDOW *win = newwin(wheight, wwidth, (height - 2)* CHEIGHT, 1);
	box(win, 0, 0);
	mvwprintw(win, 0, 1, "Enter coordinates:");
	wmove(win, 1, 1);
	wrefresh(win);
	getch();
	return 0;
}
