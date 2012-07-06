#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include "Field.h"
#include "Config.h"

#define CWIDTH  5
#define CHEIGHT 3

int print_field(int sx, int sy, int w, int h, int cw, int ch);
int print_enemy(const struct Field *f);
int print_friendly(const struct Field *f);
int read_coords(int *x, int *y, const int height, const int width);

#endif
