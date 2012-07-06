#include <stdio.h>
#include <stdlib.h>


#include "Player.h"
#include "seabattle_utils.h"


int create_players(struct Player **players, int count, struct Config *config)
{
	int i;
	int result = 0;
	for(i = 0; i < config->ships_count; i++) {

		if ((result = create_player(players + i, config)) < 0) {

			return result;
		}

	}
	return 0;
}
