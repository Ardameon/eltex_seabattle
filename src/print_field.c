#include "UI.h"

int print_field(int sx, int sy, int width, int height, int cw, int ch, char *msg)
{
	int i;
	int j;
	WINDOW *cells[height][width];

	curs_set(0);

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cells[i][j] = cwin(ch + 1, cw + 1, i * ch + sy, j * cw + sx);
		}
	}
	for (j = 1; j < height; j++) {
		mvaddch(sy, j * cw + sx, ACS_TTEE);
		mvaddch(sy + ch * height, cw * j + sx, ACS_BTEE);
	}
	for (i = 1; i < width; i++) {
		mvaddch(i * ch + sy, sx, ACS_LTEE);
		mvaddch(i * ch + sy, j * cw + sx, ACS_RTEE);
	}
	for (i = 1; i < height; i++) {
		for (j = 1; j < width; j++) {
			mvaddch(i * ch + sy, j * cw + sx, ACS_PLUS);
		}
	}
	mvprintw(ch * i + 1, sx, msg);
	curs_set(1);
	return 0;
}
