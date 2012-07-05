#include "Ship.h"
#include <stdlib.h>
#include <string.h>

struct Ship *ship_construct(int rank, const char *description) 
{
	struct Ship * ship = (struct Ship *)malloc(sizeof(struct Ship));
	ship->health = ship->rank = rank;
	ship->description = (char *)
		malloc(sizeof(char) * (strlen(description) + 1));
	strcpy(ship->description, description);
	
	return ship;
}


void ship_destruct(struct Ship *ship)
{
	free(ship->description);
	free(ship);
}
