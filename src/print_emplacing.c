#include "UI.h"
#include "Fitting_ship.h"
#include <assert.h>

static void print_ship(struct Fitting_ship *ship, int ch, int cw);
static void clear_field(int height, int width);

int print_emplacing(const struct Field *f, struct Fitting_ship *ship)
{
	int cw = CWIDTH - 1;
	int ch = CHEIGHT - 1;
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
		clear_field(f->height, f->width);
		print_enemy(f);
		mvprintw(ch * f->height + 2, 2, "Your field");
		print_ship(ship, ch, cw);
		refresh();

		c = getch();
		switch(c) {
		case KEY_LEFT:
			ship->left = (ship->left <= startx) ?
				endx - ship->length :
				ship->left - 1;
			break;
		case KEY_RIGHT:
			ship->left = (ship->left >= endx - ship->length) ?
				startx :
				ship->left + 1;
			break;
		case KEY_UP:
			ship->top = (ship->top <= starty) ?
				endy - ship->length :
				ship->top - 1;
			break;
		case KEY_DOWN:
			ship->top = (ship->top + ship->length >= endx) ?
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

static void print_ship(struct Fitting_ship *ship, int ch, int cw)
{
	int starty = 1;
	int startx = 2;
	int i;

	if (ship->orient == horizontal)
		for (i = 0; i < ship->length; i++) {
			int coordy = ship->top * ch + starty + 1;
			int coordx = (ship->left + i)* cw + startx + 2;
			mvaddch(coordy, coordx, 'S');
		}
	else
		for (i = 0; i < ship->length; i++) {
			int coordy = (ship->top + i) * ch + starty + 1;
			int coordx = ship->left * cw + startx + 2;
			mvaddch(coordy, coordx, 'S');
		}
}
