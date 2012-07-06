#include "seabattle_utils.h"
#include "Player.h"
#include <stdlib.h>
#include <stdio.h>

int shot(struct Player *player, int x, int y)
{
	struct Cell *cell = &(player->field->field[x][y]);
	struct Ship *potential_dead_ship;

	if (cell->is_attacked == 1) 
		return SHOT_ALREADY_ATTACKED;

	if (cell->ship != NULL) {
		cell->ship->health--;
		potential_dead_ship = cell->ship;
		cell->ship = player->field->dummy_ship;

		if (potential_dead_ship->health == 0) {
			player->ships_count--;
			ship_destruct(potential_dead_ship);
			
			return SHOT_SHIP_DESTROYED;
		}

		cell->is_attacked = 1;

		return SHOT_HEAT;
	} else {
		cell->is_attacked = 1;
		
		return SHOT_MISSED;
	}

	return 0;
}
