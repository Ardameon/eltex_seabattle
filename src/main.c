#include <ncurses.h>
#include "UI.h"

/* block to delete */
#include <time.h>
#include "Field.h"
#include <stdlib.h>
/* --- */

static void initialize_curses(void);

/* to delete */
static struct Field *get_field(void);
/* --- */

int main(int argc, char *argv[])
{
	/* to delete */
	struct Field *f = get_field();
	/* --- */

	int x;
	int y;
	initialize_curses();

	/* --- block to delete --- */
	print_enemy((const struct Field *)f);
	print_friendly((const struct Field *)f);
	read_coords(&x, &y, 10, 10);
	/* --- */

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

/* to delete */
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
			ptr->field[i][j] = (rand()/(double)RAND_MAX > 0.5) ? (void *)1 : NULL;
	}
	return ptr;
}
/* --- */
