#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include "Fitting_ship.h"
#include "Field.h"
#include "Config.h"
#include "Player.h"

#define CWIDTH  5
#define CHEIGHT 3

#define FITSHIP 'S'
#define UNFITSHUP 'X'
#define PLACEDSHIP 'O'

int print_field(int sx, int sy, int w, int h, int cw, int ch);
int print_enemy(const struct Field *f);
int print_friendly(const struct Field *f);
int read_coords(int *x, int *y, const int height, const int width);
int print_emplacing(const struct Field *f, struct Fitting_ship *ship);
int print_winner(struct Player *winner);

#endif
