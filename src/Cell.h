#ifndef CELL_H
#define CELL_H

#include "Ship.h"

struct Cell {
	struct Ship *ship;
	int is_attacked;
};

struct Cell *cell_construct(struct Ship *ship, int is_attacked);
void cell_destruct(struct Cell *cell);

#endif
