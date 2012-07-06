#include "UI.h"
#include "Fitting_ship.h"
#include <assert.h>

static void print_ship(struct Fitting_ship *ship);

int print_emplacing(const struct Field *f, struct Fitting_ship *ship)
{
	FILE *fp = fopen("seabattle.log", "w");

	curs_set(0);

	assert(f != NULL);
	assert(f->width != 0);
	assert(f->height != 0);
	assert(f->field != 0);

	assert(ship != NULL);
	fprintf(fp, "Ship len: %d\n", ship->length);
	fclose(fp);
	print_ship(ship);

	/*int top, left;*/
	/*int length;*/
	/*enum orientation orient;*/
	/*char check_fitting_permit;*/
	getch();

	curs_set(1);
	return 0;
}

static void print_ship(struct Fitting_ship *ship)
{
	int starty = 1;
	int startx = 2;
	int i;
	int cw = CWIDTH - 1;
	int ch = CHEIGHT - 1;

	if (ship->orient == horizontal)
		for (i = 0; i < ship->length; i++) {
			int coordy = ship->top * ch + starty + 1;
			int coordx = (ship->left + i)* cw + startx + 2;
			mvaddch(coordy, coordx, 'X');
		}
	else
		for (i = 0; i < ship->length; i++) {
			int coordy = (ship->top + i) * ch + starty + 1;
			int coordx = ship->left * cw + startx + 2;
			mvaddch(coordy, coordx, 'X');
		}
}
