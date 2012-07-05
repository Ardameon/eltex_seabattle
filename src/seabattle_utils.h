#ifndef SEABATTLE_UTILS_H
#define SEABATTLE_UTILS_H
#include "Field.h"
#include "Config.h"

int emplace_ships(struct Field *map, struct Config *config_game);
int create_player(struct Player *player, struct Config *config);
int create_players(struct Player *players, int count, struct Config *config);
int shot (struct Player*, int x, int y);
int check_winner (struct Players*);
int * generate_ships_number_per_rank(int max_ship_size);

#endif
