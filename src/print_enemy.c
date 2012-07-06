#include "UI.h"
#include <assert.h>

int print_enemy(const struct Field *f)
{
	int startx = 2;
	int starty = 1;
	int i;
	int j;

	assert(f != NULL);
	assert(f->width != 0);
	assert(f->height != 0);
	assert(f->field != NULL);
	
	print_field(startx, starty, f->width, f->height, CWIDTH - 1, CHEIGHT - 1);

	for (i = 0; i < f->height; i++) {
		assert(f->field[i] != NULL);
		for (j = 0; j < f->width; j++) {
			if (f->field[i][j] != NULL) {
				int x = startx + (CWIDTH - 1) * j + 2;
				int y = starty + (CHEIGHT - 1) * i + 1;

				mvaddch(y, x, 'X');
			}
		}
	}

	mvprintw((CHEIGHT - 1) * f->height + starty + 1, startx, "Enemy field");
	return 0;
}
