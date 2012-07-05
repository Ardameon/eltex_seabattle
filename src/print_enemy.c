#include "UI.h"

int print_enemy(const struct Field *f, const int width, const int height)
{
	int startx = 2;
	int starty = 1;
	print_field(startx, starty, width, height, CWIDTH - 1, CHEIGHT - 1);
	mvprintw((CHEIGHT - 1) * height + starty + 1, startx, "Enemy field");
	return 0;
}
