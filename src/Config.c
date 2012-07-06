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
	
	if (generate_ships_number_per_rank(config) != 0)
		return NULL;

	return config;
}

void config_destruct(struct Config *config)
{
	free(config->ships_number_per_rank);

	free(config);
}

/*
 * Generate array contains number of ships each rank
 */
int generate_ships_number_per_rank(struct Config *config)
{
	int i, count_remain_ship = config->ships_count;

	if ((config->ships_number_per_rank = 
			malloc(config->max_ship_size * sizeof(int))) == NULL)
		return -1;

	for (i = 0; (i < config->max_ship_size); ++i){
		config->ships_number_per_rank[i] = (config->max_ship_size - i)
		       	< count_remain_ship ? (config->max_ship_size - i): 
				count_remain_ship;
		count_remain_ship -= config->ships_number_per_rank[i]; 
	}

	return 0;
}
