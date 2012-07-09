#include "UI.h"
#include <stdlib.h>

static char x_to_col(int x, int startx, int w);
static int y_to_line(int y, int starty, int h);
static void clear_field(int height, int width);

int read_coords(int *retx, int *rety, const int height, const int width)
{
	int cw = CWIDTH - 1; 		/* cell width stub */
	int ch = CHEIGHT - 1; 		/* cell height stub */
	int startx = 4; 		/* line start x */
	int starty = 2; 		/* column start y */
	int endx = cw * width; 		/* line end x */
	int endy = ch * height; 	/* column end y */
	static int x = 4; 		/* current coordinate x */
	static int y = 2; 		/* current coordinate y */
	int c; 				/* reads from keyboard */

	mvprintw(LINES - 1, 1, "Press Enter to shoot; F1 to exit.\n");

	move(y, x);
	refresh();

	while ((c = getch()) != KEY_F(1)) {
		switch(c) {
		case KEY_LEFT:
			x = (x <= startx) ? endx : x - cw;
			break;
		case KEY_RIGHT:
			x = (x >= endx) ? startx : x + cw;
			break;
		case KEY_UP:
			y = (y <= starty) ? endy : y - ch;
			break;
		case KEY_DOWN:
			y = (y >= endy) ? starty : y + ch;
			break;
		case '\n':
			mvprintw(LINES - 3, 1, "You shoot to: %c%2d", 
				 x_to_col(x, startx, cw), y_to_line(y, starty, ch));
			*rety = (x - startx) / cw;
			*retx = (y - starty) / ch;
			return 0;
			break;
		default:
			break;
		}
		move(y, x);
		refresh();
	}
	endwin();
	exit(EXIT_SUCCESS);
}

static void clear_field(int height, int width)
{
	int starty = 1;
	int startx = 2;
	int i, j;
	int ch = CHEIGHT - 1;
	int cw = CWIDTH - 1;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			int y = i * ch + starty + 1;
			int x = j * cw + startx + 2;
			mvaddch(y, x, ' ');
		}
	}

}

static char x_to_col(int x, int startx, int w)
{
	return 'a' + (x - startx) / w;
}

static int y_to_line(int y, int starty, int h)
{
	return (y - starty) / h;
}
