#include <stdio.h>
#include <stdlib.h>

#include "UI.h"
#include "Player.h"
#include "UI.h"
#include "seabattle_utils.h"
#include "seabattle_errors.h"


/* create_player(struct Player*, struct Config*)
 * take 2 arguments:
 * 1. Pointer to array(uninitialized) of (struct Player).
 * 2. (struct Config) pointer, which defines field size and other game options.
 * RETURNED VALUE:
 * create_player() returns 0 on success. On error it returns a negative number
 * error code. Error codes is(will be) defined at 'error_codes.h'
 * */

int create_player(struct Player **player, struct Config *config)
{
	char *name;

	if ((name = input_name()) == NULL)
		return ERR_IO;

	if ((*player = player_construct(config, name,
		config->ships_count)) == NULL) {
	/*if player_construct() returns an error*/
		free(name);
		return ERR_PLAYER_CONSTRUCT;
	}

	if (!emplace_ships((*player)->field, config)) {
		player_destruct(*player);
		return ERR_EMPLACE;
	}

	return 0;
}



