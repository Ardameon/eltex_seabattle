#include "Ship.h"
#include <stdlib.h>
#include <string.h>

struct Ship *ship_construct(int rank, const char *description, int top, 
		int left, enum orientation orient) 
{
	struct Ship * ship = NULL;
	ship = malloc(sizeof(*ship));
	
	if (ship == NULL) return NULL;

	ship->health = ship->rank = rank;
	ship->description = (char *)
		malloc(sizeof(char) * (strlen(description) + 1));
	strcpy(ship->description, description);
	ship->top = top;
	ship->left = left;
	ship->orient = orient;
	
	return ship;
}


void ship_destruct(struct Ship *ship)
{
	free(ship->description);
	free(ship);
}
