#ifndef SHIP_H
#define SHIP_H

struct Ship {
	int health;
	int rank;
	char *description;
};

struct Ship *ship_construct(int rank, const char *description);
void ship_destruct(struct Ship *ship);

#endif
