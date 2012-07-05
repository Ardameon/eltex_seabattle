<<<<<<< HEAD
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
=======
#ifndef SEABATTLE_UTILS_H
#define SEABATTLE_UTILS_H

int * generate_ships_number_per_rank(int max_ship_size);

#endif
>>>>>>> 7b583a23a3cfe617a7fcdc609610030499d7db21
