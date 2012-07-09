#include "Field.h"
#include "Player.h"
#include "seabattle_utils.h"
#include "seabattle_errors.h"

int draw_frame(struct Player *player,
	int left, int top, enum orientation orient)
{
	struct Field *field = player->field;
	int x = left, y = top;
	int x_inc = 0, y_inc = 0;
	
	if (orient == HORIZONTAL)
		x_inc = 1;
	else
		y_inc = 1;
	
	while (field->field[x][y].ship == field->dummy_ship) {
		draw_frame_around_cell(player, x, y);
		
		x += x_inc;
		y += y_inc;
	}

	return SUCCESS;
}
