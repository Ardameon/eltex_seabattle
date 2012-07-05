#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"

struct Field {
	struct Cell **field;
	int width;
	int height;
};

struct Field *field_construct(int width, int height);
void field_destruct(struct Field *field);

#endif
