#include "seabattle_utils.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>

int shot(struct Player *player, int x, int y)
{
	struct Cell *cell = &(player->field->field[x][y]);

	if (cell->is_attacked == 1) 
		return -1;

	if (cell->ship != NULL) {
		cell->ship->health--;
		cell->is_attacked = 1;
		return 1;
	} else {
		cell->is_attacked = 1;
		return 0;
	}

	return 0;
}
