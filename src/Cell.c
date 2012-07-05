#include "Cell.h"
#include <stdlib.h>

struct Cell *cell_construct(struct Ship *ship)
{
	struct Cell * cell = (struct Cell *)malloc(sizeof(struct Cell));
	cell->ship = ship;
	cell->is_attacked = 0;
	return cell;
}

void cell_destruct(struct Cell *cell)
{
	ship_destruct(cell->ship);
	free(cell);
}
