#include <assert.h>
#include "UI.h"
#include "Fitting_ship.h"

static void print_ship(struct Fitting_ship *ship);
static void clear_field(int height, int width);

int print_emplacing(const struct Field *f, struct Fitting_ship *ship)
{
	int c = 0;
	int startx = 0;
	int starty = 0;
	int endx;
	int endy;
	short int is_placed = 0;

	curs_set(0);
	assert(f != NULL);
	assert(f->width != 0);
	assert(f->height != 0);
	assert(f->field != 0);
	assert(ship != NULL);

	endx = f->width;
	endy = f->height;

	while (c != KEY_F(1) && is_placed != 1) {
		fitting_ship(f, ship);
		clear_field(f->height, f->width);
		print_enemy(f);
		mvprintw((CHEIGHT - 1) * f->height + 2, 2, "Your field");
		print_ship(ship);
		refresh();

		c = getch();
		switch(c) {
		case KEY_LEFT:
			if (ship->orient == horizontal)
				ship->left = (ship->left <= startx) ?
					endx - ship->length :
					ship->left - 1;
			else
				ship->left = (ship->left <= startx) ?
					endx - 1:
					ship->left - 1;

			break;
		case KEY_RIGHT:
			if (ship->orient == horizontal)
				ship->left = (ship->left >= endx - ship->length) ?
					startx :
					ship->left + 1;
			else
				ship->left = (ship->left + 1 >= endx) ?
					startx :
					ship->left + 1;
			break;
		case KEY_UP:
			if (ship->orient == vertical)
				ship->top = (ship->top <= starty) ?
					endy - ship->length :
					ship->top - 1;
			else
				ship->top = (ship->top <= starty) ?
					endy - 1:
					ship->top - 1;
			break;
		case KEY_DOWN:
			if (ship->orient == vertical)
				ship->top = (ship->top + ship->length >= endx) ?
					starty : 
					ship->top + 1;
			else
				ship->top = (ship->top + 1 >= endx) ?
					starty : 
					ship->top + 1;
			break;
		case '\n':
			is_placed = 1;
			break;
		default:
			break;
		}
	}
	curs_set(1);
	return 0;
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

static void print_ship(struct Fitting_ship *ship)
{
	int starty = 1;
	int startx = 2;
	int ch = CHEIGHT - 1;
	int cw = CWIDTH - 1;
	int i;
	int symbol = (ship->check_fitting_permit) ? FITSHIP : UNFITSHUP;

	if (ship->orient == horizontal)
		for (i = 0; i < ship->length; i++) {
			int coordy = ship->top * ch + starty + 1;
			int coordx = (ship->left + i)* cw + startx + 2;
			mvaddch(coordy, coordx, symbol);
		}
	else
		for (i = 0; i < ship->length; i++) {
			int coordy = (ship->top + i) * ch + starty + 1;
			int coordx = ship->left * cw + startx + 2;
			mvaddch(coordy, coordx, symbol);
		}
}
