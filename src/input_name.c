#include "UI.h"
#include <stdlib.h>

char *input_name(void)
{
	char *name = malloc(sizeof(char) * 36);
	int height = 3;
	int width = 40;
	int startx = (COLS - width) / 2;
	int starty = (LINES - height) / 2;

	WINDOW *win = newwin(height, width, starty, startx);
	clear();
	box(win, 0, 0);
	mvwprintw(win, 0, 1, "Enter your name");
	wrefresh(win);
	wmove(win, 1, 1);
	noraw();
	echo();
	wscanw(win, "%[a-zA-z]", name);
	raw();
	noecho();


	return name;
}
