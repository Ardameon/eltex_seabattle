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
		
		if (shot_val == 0) {
			current_player_index = (current_player_index + 1) % 2;
		} else if (shot_val == 1) {
			winner_index = check_winner(players);
		} else { 
			continue;
		}

	}

	print_winner(players[winner_index]);

	return SUCCESS;
}

int print_fields(struct Player **players, int friendly_player_index)
{
	int err_code;
	int i;

	err_code = print_friendly(players[friendly_player_index]->field);

	if (err_code != SUCCESS)
		return err_code;

	for (i = 0; i < 2; ++i) {
		if (i != friendly_player_index) {
			err_code = print_enemy(players[i]->field);

			if (err_code != SUCCESS)
				return err_code;
		}
	}

	return SUCCESS;
}
