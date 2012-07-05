#ifndef CONFIG_H
#define CONFIG_H

struct Config {
	int field_width;
	int field_height;
	int ships_count;
	int max_ship_size;
	int *ships_number_per_rank;
};

struct Config *config_construct(int field_width, int field_height,
	int ships_count, int max_ships_size);
void config_destruct(struct Config *config);

#endif /* CONFIG_H */
