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
	int ships_count, int max_ship_size);
void config_destruct(struct Config *config);
int *generate_ships_number_per_rank(int ships_count, int max_ships_size);

#endif /* CONFIG_H */
