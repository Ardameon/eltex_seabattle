#include "UI.h"
#include <stdlib.h>

int print_friendly(const struct Field *f, const int width, const int height)
{
	print_field(width * CWIDTH + 10, 0,
			width, height,
			CWIDTH - 1, CHEIGHT - 1,
			"Your field");
	return 0;
	/*int i;*/
	/*int j;*/
	/*int offset = width * CWIDTH + 10;*/
	/*int ch = CHEIGHT - 1;*/
	/*int cw = CWIDTH - 1;*/
	/*WINDOW *cells[width][height];*/

	/*curs_set(0);*/

	/*for (i = 0; i < height; i++) {*/
		/*for (j = 0; j < width; j++) {*/
			/*cells[i][j] = cwin(ch + 1, cw + 1, i * ch, j * cw + offset);*/
		/*}*/
	/*}*/
	/*for (j = 1; j < height; j++) {*/
		/*mvaddch(0, j * cw + offset, ACS_TTEE);*/
		/*mvaddch(ch * height, cw * j + offset, ACS_BTEE);*/
	/*}*/
	/*for (i = 1; i < width; i++) {*/
		/*mvaddch(i * ch, offset, ACS_LTEE);*/
		/*mvaddch(i * ch, j * cw + offset, ACS_RTEE);*/
	/*}*/
	/*for (i = 1; i < height; i++) {*/
		/*for (j = 1; j < width; j++) {*/
			/*mvaddch(i * ch, j * cw + offset, ACS_PLUS);*/
		/*}*/
	/*}*/
	/*mvprintw(ch * i + 1, offset, "Your field");*/
	/*curs_set(1);*/
	/*return 0;*/
}
