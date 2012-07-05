#include "seabattle_utils.h"

int *generate_ships_numbers_per_rank(int max_ships_size){
	int *array = malloc(max_ships_size * sizeof(int)), i;
	for (i = 0; i < max_ships_size; i++)
		array[i] = max_ships_size - i;
	return array;
}
