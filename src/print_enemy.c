#include <assert.h>
#include "UI.h"

static void clear_field(int height, int width);

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
	clear_field(f->height, f->width);

	for (i = 0; i < f->height; i++) {
		assert(f->field[i] != NULL);
		for (j = 0; j < f->width; j++) {
			int x = startx + cw * j + 2;
			int y = starty + ch * i + 1;

			if (f->field[i][j].is_attacked == 1) {
				mvaddch(y, x, WASATTACKED);
			}
			if (f->field[i][j].ship == f->dummy_ship) {
				mvaddch(y, x, 'n');
			}
		}
	}

	mvprintw(ch * f->height + starty + 1, startx, "Enemy field");
	return 0;
}

static void clear_field(int height, int width)
{
	int starty = 1;
	int startx = 2;
	int i, j;
	int ch = CHEIGHT - 1;
	int cw = CWIDTH - 1;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int y = i * ch + starty + 1;
			int x = j * cw + startx + 2;
			mvaddch(y, x, ' ');
		}
	}

}
