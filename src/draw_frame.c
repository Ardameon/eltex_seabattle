#include "Field.h"
#include "Player.h"
#include "seabattle_utils.h"
#include "seabattle_errors.h"

int draw_frame(struct Player *player,
	int left, int top, enum orientation orient)
{
	struct Field *field = player->field;
	int width = player->field->width, height = player->field->height;
	int x = top, y = left;
	int x_inc = 0, y_inc = 0;
	
	if (orient == HORIZONTAL)
		y_inc = 1;
	else
		x_inc = 1;
	
	while (x < width && y < height &&
	       field->field[x][y].ship == field->dummy_ship) {
		draw_frame_around_cell(player, x, y);
		
		x += x_inc;
		y += y_inc;
	}

	return SUCCESS;
}
