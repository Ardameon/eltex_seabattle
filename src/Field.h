#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include "Config.h"

struct Field {
	struct Cell **field;
	struct Ship *dummy_ship;
	int width;
	int height;
};

struct Field *field_construct(struct Config *conf);
void field_destruct(struct Field *field);

#endif
