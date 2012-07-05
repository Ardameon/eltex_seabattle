#ifndef PLAYER_H
#define PLAYER_H

#include "Field.h"

struct Player {
	struct Field *field;
	char *name;
	int ships_count;
};

struct Player *player_construct(struct Field *field, const char *name,
	int ships_count);
void player_destruct(struct Player *player);

#endif
