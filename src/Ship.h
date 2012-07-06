#ifndef SHIP_H
#define SHIP_H

enum orientation { horizontal, vertical };

struct Ship {
	int health;
	int rank;
	char *description;
	int top, left;
	enum orientation orient;
};

struct Ship *ship_construct(int rank, const char *description, 
		int top, int left, enum orientation orient);
void ship_destruct(struct Ship *ship);

#endif
