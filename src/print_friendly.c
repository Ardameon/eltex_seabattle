#include "UI.h"

int print_friendly(const struct Field *f, const int width, const int height)
{
	int i;
	int j;
	int offset = width * CWIDTH + 10;
	int ch = CHEIGHT;
	int cw = CWIDTH;
	WINDOW *cells[width][height];
	curs_set(0);

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cells[i][j] = cwin(ch, cw, i * (ch - 1), j * (cw - 1) + offset);
		}
	}
	mvprintw((ch - 1) * (i + 1), offset, "Your field");
	getch();
	curs_set(1);
	return 0;
}
