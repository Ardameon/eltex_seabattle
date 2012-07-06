#ifndef FITTING_SHIP_H
#define FITTING_SHIP_H

#include "Ship.h"
#include "Field.h"

struct Fitting_ship{
	int top, left;
	int length;
	enum orientation orient;
	char check_fitting_permit;
};

struct Fitting_ship *fitting_ship_construct(struct Field *map, int rank);
void Fitting_ship_destruct(struct Fitting_ship *fitt_ship);

int add_ship_on_field(struct Field *map, struct Fitting_ship *fitt_ship);
int check_fitting_cell(const struct Field *map, int left, int top);
int check_fitting_cells(const struct Field *map, int left, int top);
int rotation(struct Field *map, struct Fitting_ship *fitt_ship);
int fitting_ship(const struct Field *map, struct Fitting_ship *fitt_ship);
#endif
