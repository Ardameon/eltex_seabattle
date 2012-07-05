#include "UI.h"
#include <stdlib.h>

int print_friendly(const struct Field *f, const int width, const int height)
{
	int startx = width * CWIDTH + 10;
	int starty = 1;
	print_field(startx, starty, width, height, CWIDTH - 1, CHEIGHT - 1);
	mvprintw((CHEIGHT - 1) * height + starty + 1, startx, "Your field");
	return 0;
}
