#include "UI.h"

int print_enemy(const struct Field *f, const int width, const int height)
{
	int i;
	int j;
	int ch = CHEIGHT; 		/* cell height stub */
	int cw = CWIDTH; 		/* cell width stub  */
	WINDOW *cells[width][height];
	curs_set(0);

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			cells[i][j] = cwin(ch, cw, i * (ch - 1), j * (cw - 1));
		}
	}
	for (j = 1; j < height; j++) {
		mvaddch(0, (cw - 1)* j, ACS_TTEE);
		mvaddch((ch - 1)* height, (cw - 1)* j, ACS_BTEE);
	}
	for (i = 1; i < width; i++) {
		mvaddch(i * (ch - 1), 0, ACS_LTEE);
		mvaddch(i * (ch - 1), (cw - 1)* j, ACS_RTEE);
	}
	for (i = 1; i < height; i++) {
		for (j = 1; j < width; j++) {
			mvaddch((ch - 1)* i, (cw - 1)* j, ACS_PLUS);
		}
	}
	mvprintw((ch - 1) * (i + 1), 1, "Enemy field");
	curs_set(1);
	return 0;
}
