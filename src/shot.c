#include "seabattle_utils.h"

int shot(struct Player*, int x, int y)
{
if ((Player->field->field[x][y].ship == NULL) && (Player->field->field[x][y].is_attacked == 0)) {
	Player->field->field[x][y].is_attacked = 1;
	return 0;
	}
if ((Player->field->field[x][y].ship == NULL) && (Player->field->field[x][y].is_attacked == 1)) {
	
	return -1;
	}
if ((Player->field->field[x][y].ship != NULL) && (Player->field->field[x][y].is_attacked == 0)) {
	Player->field->field[x][y].ship->health--;
	if (Player->field->field[x][y].ship->health == 0) Player->ships_count--;
	return 1;
	}
if ((Player->field->field[x][y].ship != NULL) && (Player->field->field[x][y].is_attacked == 1)) {
	
	return -1;
	}



}
