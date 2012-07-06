#include "UI.h"

int print_field(int startx, int starty, int width, int height, int cw, int ch)
{
	int i;
	int j;
	WINDOW *cells[height][width];
	for (i = 0; i < height; i++) {
		int y = i * ch + starty;
		for (j = 0; j < width; j++) {
			int x = j * cw + startx;

			cells[i][j] = cwin(ch + 1, cw + 1, y, x);/* new window */
			mvaddch(y + 1, startx - 2, i + '0'); 	 /* y indexing */
			mvaddch(starty - 1, x + 2, j + 'a'); 	 /* x indexing */
		}
	}

	mvaddch(starty, startx, ACS_ULCORNER);
	mvaddch(starty, startx + cw * width, ACS_URCORNER);
	mvaddch(starty + ch * height, startx, ACS_LLCORNER);
	mvaddch(starty + ch * height, startx + cw * width, ACS_LRCORNER);

	for (j = 1; j < width; j++) {
		int x = j * cw + startx;
		int y_bottom = starty + ch * height;
		mvaddch(starty, x, ACS_TTEE); 		/* field top side */
		mvaddch(y_bottom, x, ACS_BTEE); 	/* field bottom side */
	}

	for (i = 1; i < height; i++) {
		int y = i * ch + starty;
		int x_right = startx + width * cw;
		mvaddch(y, startx, ACS_LTEE); 		/* field left side */
		mvaddch(y, x_right, ACS_RTEE); 		/* field right side */
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
