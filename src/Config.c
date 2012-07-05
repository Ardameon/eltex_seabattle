#include <stdlib.h>
#include "Config.h"

struct Config *config_construct(int field_width, int field_height,
	int ships_count, int max_ships_size){
	struct Config *ptr = malloc(sizeof(struct Config));
	ptr->field_width = field_width;
	ptr->field_height = field_height;
	ptr->ships_count = ships_count;
	ptr->max_ship_size = max_ships_size;
	ptr->ships_number_per_rank = generate_ships_number_per_rank(ships_count, 
			max_ships_size);
	return ptr;
}

void config_destruct(struct Config *config){
	free(config->ships_number_per_rank);
}
int *generate_ships_number_per_rank(int ships_count, int max_ships_size){
	int *array = malloc(max_ships_size * sizeof(int)), i;
	for (i = 0; i < max_ships_size; i++)
		array[i] = max_ships_size - i;
	return array;	
}

