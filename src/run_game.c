#include "seabattle_utils.h"
#include "seabattle_errors.h"
#include "Player.h"
#include "Field.h"
#include "UI.h"

int run_game(struct Player **players)
{
	int shot_val;
	int current_player_index = 0;
	int shot_x, shot_y;
	int destroyed_ship_left, destroyed_ship_top;
	enum orientation orient;
	int winner_index = -1;
	struct Player *current_player;
	struct Field *current_player_field;

	while (winner_index == -1) {
		current_player = players[current_player_index];
		current_player_field = current_player->field;
		print_fields(players, current_player_index);
		read_coords(&shot_x, &shot_y, current_player_field->height,
			current_player_field->width);
		shot_val = shot(players[(current_player_index + 1) % 2],
			shot_x, shot_y);
		
		if (shot_val == SHOT_MISSED) {
			current_player_index = (current_player_index + 1) % 2;
		} else if (shot_val == SHOT_SHIP_DESTROYED) {
			winner_index = check_winner(players);
			/*draw_frame(current_player->field,*/
				/*destroyed_ship_left, destroyed_ship_top,*/
				/*orient);*/
		}
	}

	print_winner(players[winner_index]);

	return SUCCESS;
}
