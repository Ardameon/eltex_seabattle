#include "seabattle_utils.h"
#include "seabattle_errors.h"
#include "Player.h"
#include "UI.h"

int print_fields(struct Player **players, int friendly_player_index)
{
	int err_code;
	int i;

	err_code = print_friendly(players[friendly_player_index]);

	if (err_code != SUCCESS)
		return err_code;

	for (i = 0; i < 2; ++i) {
		if (i != friendly_player_index) {
			err_code = print_enemy(players[i]);

			if (err_code != SUCCESS)
				return err_code;
		}
	}

	return SUCCESS;
}
