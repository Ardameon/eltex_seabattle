#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "Player.h"
#include "Config.h"
#include "seabattle_utils.h"

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10
#define SHIPS_COUNT 10
#define MAX_SHIP_SIZE 4

#define PLAYERS_COUNT 2

static void initialize_curses(void);

int main(int argc, char *argv[])
{
	struct Player **players = NULL;
	struct Config *config = NULL;
	srand(time(NULL));
	initialize_curses();
	
	players = malloc(sizeof(*players) * PLAYERS_COUNT);

	config = config_construct(FIELD_WIDTH, FIELD_HEIGHT,
				  SHIPS_COUNT, MAX_SHIP_SIZE);

	create_players(players, PLAYERS_COUNT, config);

	run_game(players);

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
