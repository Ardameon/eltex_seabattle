#include "seabuttle_utils.h"
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
		print_friendly(current_player_field);
		print_enemy(current_player_field);
		read_coords(&shot_x, &shot_y, current_player_field->height,
			current_player_field->width);
		shot_val = shot(current_player, shot_x, shot_y);
		
		if (shot_val == 0) {
			current_player_index = (current_player_index + 1) % 2;
		} else if (shot_val == 1) {
			winner_index = check_winner(current_player);
		} else { 
			continue;
		}

		print_friendly(current_player_field);
		print_enemy(current_player_field);
	}

	print_winner(players[winner_index]);

	return 0;
}
