#include <ncurses.h>
#include <stdlib.h>
#include "Field.h"
#include "UI.h"

static void initialize_curses(void);
static struct Field *get_field(void);

int main(int argc, char *argv[])
{
	struct Field *f = get_field();
	int x;
	int y;
	initialize_curses();
	print_enemy((const struct Field *)f, 10, 10);
	print_friendly((const struct Field *)f, 10, 10);
	read_coords(&x, &y, 10, 10);

	endwin();
	return 0;
}

static struct Field *get_field(void)
{
	struct Field *f = (struct Field *)malloc(sizeof(struct Field));
	return f;
}

static void initialize_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}
