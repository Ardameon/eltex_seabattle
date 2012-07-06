#include <stdio.h>
#include <stdlib.h>

#include "Player.h"
#include "seabattle_utils.h"


/* create_player(struct Player*, struct Config*)
 * take 2 arguments:
 * 1. Pointer to array(uninitialized) of (struct Player).
 * 2. (struct Config) pointer, which defines field size and other game options.
 * RETURNED VALUE:
 * create_player() returns 0 on success. On error it returns a negative number
 * error code. Error codes is(will be) defined at 'error_codes.h'
 * */

int create_player(struct Player *player, struct Config *config)
{
	struct Field* field;
	char* name;
	name = (char*) malloc(sizeof(char) * 128);
	if (!fgets(name, 128, stdin)) {
		free(name);
		return -1;
	}

	if ((field = field_construct(config->field_width,
		config->field_height)) == NULL) {
	/*if field_construct() returns an error*/
		free(name);
		return -2;
	}

	if (player_construct(field, "unnamed", config->ships_count) == NULL) {
	/*if player_construct() returns an error*/
		ree(name);
		field_destruct(field);
		return -3;

	}

	return 0;
}



