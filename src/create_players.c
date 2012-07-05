#include <stdio.h>
#include <stdlib.h>


#include "Player.h"
#include "seabattle_utils.h"


int create_players(struct Player *players, int count, struct Config *config)
{

	int i = 0;
	for(i; i < config->ships_count; i++) {
		create_player(players + i, config);
	}

	return 1;
}
