#ifndef SEABATTLE_UTILS_H
#define SEABATTLE_UTILS_H
#include "Field.h"
#include "Config.h"
#include "Player.h"

int emplace_ships(struct Field *map, struct Config *config_game);
int create_player(struct Player **player, struct Config *config);
int create_players(struct Player **players, int count, struct Config *config);
int shot(struct Player *player, int x, int y);
int check_winner(struct Player **player);
int finalize_field(struct Player *player);
int run_game(struct Player **players);
int print_fields(struct Player **players, int friendly_player_index);

#endif
