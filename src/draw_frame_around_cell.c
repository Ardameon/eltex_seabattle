#include <stdlib.h>

#include "Player.h"
#include "seabattle_utils.h"
#include "seabattle_errors.h"

int draw_frame_around_cell(struct Player *player, int x, int y)
{
	int field_width = player->field->width;
	int field_height = player->field->height;
	int i, j;

	for (i = x - 1; i <= x + 1; ++i) {
		for (j = y - 1; j <= y + 1; ++j) {
			if (i >= 0 && i < field_width &&
			    j >= 0 && j < field_height) {
				shot(player, i, j, NULL, NULL, NULL);
			}
		}
	}

	return SUCCESS;
}
