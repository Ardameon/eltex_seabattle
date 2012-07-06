#include <ncurses.h>
#include "UI.h"
#include <time.h>
#include "Field.h"
#include <stdlib.h>
#include "Fitting_ship.h"

static void initialize_curses(void);
static struct Field *get_field(void);

int main(int argc, char *argv[])
{
	struct Field *f = get_field();
	struct Fitting_ship *s1, *s2;
	int x;
	int y;
	initialize_curses();

	s1 = fitting_ship_construct(f, 2);
	s2 = fitting_ship_construct(f, 3);
	s2->orient = vertical;

	print_enemy((const struct Field *)f);
	print_friendly((const struct Field *)f);
	print_emplacing((const struct Field *)f, s1);
	print_emplacing((const struct Field *)f, s2);
	read_coords(&x, &y, 10, 10);

	endwin();
	return 0;
}

static void initialize_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

static struct Field *get_field(void)
{
	struct Field *ptr = (struct Field *)malloc(sizeof(struct Field));
	int i,j;
	srand(time(NULL));
	ptr->width = 10;
	ptr->height = 10;
	ptr->field = malloc(ptr->height * sizeof(struct Cell **));
	for (i = 0; i < ptr->height; i++){
		ptr->field[i] = (struct Cell **)malloc(ptr->width * sizeof(struct Cell *)); 
		for (j = 0; j < ptr->width; j++)
			ptr->field[i][j] = NULL;
			/*ptr->field[i][j] = (rand()/(double)RAND_MAX > 0.5) ? (void *)1 : NULL;*/
	}
	return ptr;
}
