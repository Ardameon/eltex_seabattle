#include "UI.h"

int print_field(int sx, int sy, int width, int height, int cw, int ch)
{
	int i;
	int j;
	WINDOW *cells[height][width];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cells[i][j] = cwin(ch + 1, cw + 1,
					i * ch + sy, j * cw + sx);
		}
	}

	mvaddch(sy - 1, sx + 2, 'a');
	for (j = 1; j < height; j++) {
		mvaddch(sy - 1, j * cw + sx + 2, j + 'a');
		mvaddch(sy, j * cw + sx, ACS_TTEE);
		mvaddch(sy + ch * height, cw * j + sx, ACS_BTEE);
	}
	mvaddch(sy + 1, sx - 2, '1');
	for (i = 1; i < width; i++) {
		mvaddch(i * ch + sy + 1, sx - 2, i + 1 + '0');
		mvaddch(i * ch + sy, sx, ACS_LTEE);
		mvaddch(i * ch + sy, j * cw + sx, ACS_RTEE);
	}
	for (i = 1; i < height; i++) {
		for (j = 1; j < width; j++) {
			mvaddch(i * ch + sy, j * cw + sx, ACS_PLUS);
		}
	}
	return 0;
}
