#ifndef SEABATTLE_UTILS_H
#define SEABATTLE_UTILS_H

/* int create_player(struct Player*, struct Config*)
 * takes 2 arguments:
 * 1. Pointer to array(uninitialized) of (struct Player).
 * 2. (struct Config) pointer, which defines field size and other game options.
 * RETURNED VALUE:
 * create_player() returns 0 on success. On error it returns a negative number
 * error code. Error codes is(will be) defined at 'error_codes.h'
 * */
int create_player(struct Player *player, struct Config *config);

/*
 * int create_players(struct Player*, int, struct Config*)
 * Takes almost the same arguments which takes create_players(), unless
 * second integer argument - count.
 * RETURNED VALUE:
 * returns 0 on success. On error returns error codes defined
 * at 'error_codes.h'
 * */
int create_players(struct Player *players, int count, struct Config *config);

/* Function make a shot into a field with coordinates (x, y)
 * Checking if we shot the ship or not.
 * Redusing its health.
 * Input parametrs: Structure Player, Coordinates (x, y)
 * Output data: 0 1 -1 in different cases.
 * */
int shot (struct Player*, int x, int y);

/*Checking ships count
 * Input parammetrs: Massive of structures Player
 * Output data: Returns index of winner.
 * */
int check_winner (struct Players*);

int * generate_ships_number_per_rank(int max_ship_size);

#endif
