#include <stdlib.h>

#include "Config.h"

struct Config *config_construct(int field_width, int field_height,
	int ships_count, int max_ships_size)
{
	struct Config *config;
       
	config = malloc(sizeof(*config));

	config->field_width = field_width;
	config->field_height = field_height;
	config->ships_count = ships_count;
	config->max_ship_size = max_ships_size;
	config->ships_number_per_rank =
		generate_ships_number_per_rank(max_ships_size);

	return config;
}

void config_destruct(struct Config *config)
{
	free(config->ships_number_per_rank);

	free(config);
}

/*
 * Generate array contains number of ships each rank
 * Parameters:
 * 	max_ships_size - max rank of ship
 * Return value:
 * 	generated array
 */
int *generate_ships_number_per_rank(int max_ships_size)
{
	int *array;
	int i;
		
	array = malloc(max_ships_size * sizeof(*array));

	for (i = 0; i < max_ships_size; ++i)
		array[i] = max_ships_size - i;

	return array;	
}
