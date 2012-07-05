#ifndef UI_H
#define UI_H

#include <ncurses.h>
#include "Field.h"
#include "Config.h"

#define CWIDTH  5
#define CHEIGHT 3

int print_field(int sx, int sy, int w, int h, int cw, int ch, char *msg);
int print_enemy(const struct Field *f, const int width, const int height);
int print_friendly(const struct Field *f, const int width, const int height);
int read_coords(int *x, int *y, const int height, const int width);
WINDOW *cwin(int height, int width, int starty, int startx);
int draw_box(WINDOW *win, int h, int w, int sy, int sx);

#endif
