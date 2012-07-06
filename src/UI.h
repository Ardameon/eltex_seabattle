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
#define WASATTACKED '+'

int print_field(int sx, int sy, int w, int h, int cw, int ch);
int print_enemy(struct Player *p);
int print_friendly(struct Player *p);
int read_coords(int *x, int *y, const int height, const int width);
int print_emplacing(const struct Field *f, struct Fitting_ship *ship);
int print_winner(struct Player *winner);
char *input_name(void);
int draw_frame(struct Field *field, int x, int y);

#endif
