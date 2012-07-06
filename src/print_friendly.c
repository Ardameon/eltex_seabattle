#include "UI.h"
#include <assert.h>

int print_friendly(const struct Field *f)
{
	const int startx = f->width * CWIDTH + 10;
	const int starty = 1;
	const int cw = CWIDTH - 1;
	const int ch = CHEIGHT - 1;

	assert(f != NULL);
	assert(f->width != 0);
	assert(f->height != 0);
	assert(f->field != NULL);

	print_field(startx, starty, f->width, f->height, cw, ch);
	mvprintw(ch * f->height + starty + 1, startx, "Your field");
	return 0;
}
