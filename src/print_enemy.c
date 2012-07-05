#include "UI.h"

int print_enemy(const struct Field *f, const int width, const int height)
{
	print_field(0, 0,
			width, height,
			CWIDTH - 1, CHEIGHT - 1,
			"Enemy field");
	return 0;
	/*int i;*/
	/*int j;*/
	/*int ch = CHEIGHT - 1; 		[> cell height stub <]*/
	/*int cw = CWIDTH - 1; 		[> cell width stub  <]*/
	/*WINDOW *cells[width][height];*/
	/*curs_set(0);*/

	/*for (i = 0; i < height; i++) {*/
		/*for (j = 0; j < width; j++) {*/
			/*cells[i][j] = cwin(ch + 1, cw + 1, i * ch, j * cw);*/
		/*}*/
	/*}*/
	/*for (j = 1; j < height; j++) {*/
		/*mvaddch(0, j * cw, ACS_TTEE);*/
		/*mvaddch(ch * height, j * cw, ACS_BTEE);*/
	/*}*/
	/*for (i = 1; i < width; i++) {*/
		/*mvaddch(i * ch, 0, ACS_LTEE);*/
		/*mvaddch(i * ch, j * cw, ACS_RTEE);*/
	/*}*/
	/*for (i = 1; i < height; i++) {*/
		/*for (j = 1; j < width; j++) {*/
			/*mvaddch(i * ch, j * cw, ACS_PLUS);*/
		/*}*/
	/*}*/
	/*mvprintw(ch * i + 1, 1, "Enemy field");*/
	/*curs_set(1);*/
	/*return 0;*/
}
