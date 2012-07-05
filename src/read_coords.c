#include "UI.h"

static char x_to_col(int x, int startx, int w);
static int y_to_line(int y, int starty, int h);

int read_coords(int *retx, int *rety, const int height, const int width)
{
	int cw = CWIDTH - 1; 		/* cell width stub */
	int ch = CHEIGHT - 1; 		/* cell height stub */
	int startx = 4; 		/* line start x */
	int starty = 2; 		/* column start y */
	int endx = cw * width; 		/* line end x */
	int endy = ch * height; 	/* column end y */
	int x = startx; 		/* current coordinate x */
	int y = starty; 		/* current coordinate y */
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
			break;
		default:
			break;
		}
		move(y, x);
		refresh();
	}
	*retx = x - 'a';
	*rety = y - 1;
	return 0;
}

static char x_to_col(int x, int startx, int w)
{
	return 'a' + (x - startx) / w;
}

static int y_to_line(int y, int starty, int h)
{
	return 1 + (y - starty) / h;
}
