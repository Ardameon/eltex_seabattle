#include <ncurses.h>

static void initialize_curses(void);

int main(int argc, char *argv[])
{
	initialize_curses();

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
