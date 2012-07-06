#include <stdio.h>
#include <stdlib.h>
#include "seabattle_utils.h"
#include "Fitting_ship.h"

int emplace_ships(struct Field *map, struct Config *config_game){
	struct Fitting_ship *fitt_ship = NULL;
	int i, j;
	for (i = config_game->max_ship_size - 1; i >= 0; i--)
		for (j = 0; j < config_game->ships_number_per_rank[i]; j++){
			fitt_ship = fitting_ship_construct(map, i + 1); 
			do {
				fitt_ship->top = rand() % map->height;
				fitt_ship->left = rand() % map->width;
				if ((rand() & 0x01) == 1)
					fitt_ship->orient = horizontal;
				else
					fitt_ship->orient = vertical;
			} while (!fitting_ship(map, fitt_ship));
		add_ship_on_field(map, fitt_ship);
		free(fitt_ship);
	}
	return 0;
}
