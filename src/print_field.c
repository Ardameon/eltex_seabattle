#include "UI.h"

int print_field(int startx, int starty, int width, int height, int cw, int ch)
{
	int i;
	int j;
	WINDOW *cells[height][width];
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int y = i * ch + starty;
			int x = j * cw + startx;
			cells[i][j] = cwin(ch + 1, cw + 1, y, x);
		}
	}

	mvaddch(starty - 1, startx + 2, 'a');
	for (j = 1; j < height; j++) {
		int x = j * cw + startx;
		int y_bottom = starty + ch * height;

		mvaddch(starty - 1, x + 2, j + 'a');
		mvaddch(starty, x, ACS_TTEE);
		mvaddch(y_bottom, x, ACS_BTEE);
	}
	mvaddch(starty + 1, startx - 2, '1');
	for (i = 1; i < width; i++) {
		int y = i * ch + starty;
		int x_right = j * cw + startx;

		mvaddch(y + 1, startx - 2, i + 1 + '0');
		mvaddch(y, startx, ACS_LTEE);
		mvaddch(y, x_right, ACS_RTEE);
	}
	for (i = 1; i < height; i++) {
		for (j = 1; j < width; j++) {
			int y = i * ch + starty;
			int x = j * cw + startx;

			mvaddch(y, x, ACS_PLUS);
		}
	}
	return 0;
}
