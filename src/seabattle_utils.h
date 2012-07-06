#ifndef SEABATTLE_UTILS_H
#define SEABATTLE_UTILS_H
#include "Field.h"
#include "Config.h"
#include "Player.h"
#include "Ship.h"

#define SHOT_ALREADY_ATTACKED -1
#define SHOT_MISSED 0
#define SHOT_HEAT 1
#define SHOT_SHIP_DESTROYED 2


int emplace_ships(struct Field *map, struct Config *config_game);
int create_player(struct Player **player, struct Config *config);
int create_players(struct Player **players, int count, struct Config *config);
int shot(struct Player *player, int x, int y,
	 int *destroyed_ship_left,
	 int *destroyed_ship_top,
	 enum orientation *orient);
int check_winner(struct Player **player);
int finalize_field(struct Player *player);
int run_game(struct Player **players);
int print_fields(struct Player **players, int friendly_player_index);

#endif
