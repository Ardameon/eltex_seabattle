#include <assert.h>
#include "UI.h"

int print_enemy(const struct Field *f)
{
	int i;
	int j;
	const int startx = 2;
	const int starty = 1;
	const int cw = CWIDTH - 1;
	const int ch = CHEIGHT - 1;

	assert(f != NULL);
	assert(f->width != 0);
	assert(f->height != 0);
	assert(f->field != NULL);
	
	print_field(startx, starty, f->width, f->height, cw, ch);

	for (i = 0; i < f->height; i++) {
		assert(f->field[i] != NULL);
		for (j = 0; j < f->width; j++) {
			if (f->field[i * f->width + j] != NULL) {
				int x = startx + cw * j + 2;
				int y = starty + ch * i + 1;

				mvaddch(y, x, PLACEDSHIP);
			}
		}
	}

	mvprintw(ch * f->height + starty + 1, startx, "Enemy field");
	return 0;
}
