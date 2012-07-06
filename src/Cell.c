#include "Cell.h"
#include <stdlib.h>

struct Cell *cell_construct(struct Ship *ship)
{
	struct Cell * cell = NULL;
	cell = malloc(sizeof(*cell));

	if (ship == NULL) {
		free(cell);
		return NULL;
	}

	if (cell == NULL) {
		ship_destruct(ship);
		return NULL;
	}

	cell->ship = ship;
	cell->is_attacked = 0;
	return cell;
}

void cell_destruct(struct Cell *cell)
{
	ship_destruct(cell->ship);
	free(cell);
}
