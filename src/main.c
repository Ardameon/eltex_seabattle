#include <ncurses.h>

static void initialize_curses(void);
static void greeting(void);

int main(int argc, char *argv[])
{
	initialize_curses();
	greeting();

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

static void greeting(void)
{
	char *msg = "Seabattle";

	box(stdscr, 0, 0);
	mvprintw(1, 1, msg);
	refresh();
	getch();
}
