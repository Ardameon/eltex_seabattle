#include "seabattle_utils.h"

int check_winner(struct Player **player)
{
	int i = 0;
	for (i = 0; i < 2; i++) {
		if (player[i]->ships_count == 0) 
			return (i + 1 ) % 2;
	}

	return -1;
}


