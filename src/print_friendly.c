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

	for (j = 1; j < height; j++) {
		mvaddch(0, (cw - 1)* j + offset, ACS_TTEE);
		mvaddch((ch - 1)* height, (cw - 1)* j + offset, ACS_BTEE);
	}
	for (i = 1; i < width; i++) {
		mvaddch(i * (ch - 1), offset, ACS_LTEE);
		mvaddch(i * (ch - 1), (cw - 1)* j + offset, ACS_RTEE);
	}
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cells[i][j] = cwin(ch, cw, i * (ch - 1), j * (cw - 1) + offset);
		}
	}
	for (i = 1; i < height; i++) {
		for (j = 1; j < width; j++) {
			mvaddch((ch - 1)* i, (cw - 1)* j + offset, ACS_PLUS);
		}
	}
	mvprintw((ch - 1) * (i + 1), offset, "Your field");
	getch();
	curs_set(1);
	return 0;
}
