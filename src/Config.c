#include "Config.h"
#include "seabattle_utils.h"

struct Config *config_construct(int field_width, int field_height,
	int ships_count, int max_ship_size)
{
	struct Config *config;

	if ((config = malloc(sizeof(*config))) == NULL)
		return NULL;

	config.field_width = field_width;
	config.field_height = fieeld_height;
	confid.ships_count = ships_count;
	config.max_ship_size = max_ship_size;
	config.ships_number_per_rank =
		generate_ships_number_per_rank(max_ship_size);

	if (config.ships_number_per_rank == NULL) {
		free(config);

		return NULL;
	}

	return config;
}

void config_destruct(struct Config *config)
{
	free(config.ships_number_per_rank);

	free(config);
}
