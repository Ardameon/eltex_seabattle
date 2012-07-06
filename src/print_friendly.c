#include "UI.h"
#include <assert.h>

int print_friendly(const struct Field *f)
{
	int startx;
	int starty;

	assert(f != NULL);
	assert(f->width != 0);
	assert(f->height != 0);
	assert(f->field != NULL);

	startx = f->width * CWIDTH + 10;
	starty = 1;

	print_field(startx, starty, f->width, f->height, CWIDTH - 1, CHEIGHT - 1);
	mvprintw((CHEIGHT - 1) * f->height + starty + 1, startx, "Your field");
	return 0;
}
