#include <stdlib.h>
#include <string.h>

#include "Player.h"

struct Player *player_construct(struct Field *field, const char *name,
	int ships_count)
{
	struct Player *player;

	if ((player = malloc(sizeof(*player))) == NULL)
		return NULL;

	player.name = calloc(strlen(name), sizeof(*player.name));
	
	if (player.name == NULL) {
		free(player);

		return NULL;
	}

	strcpy(player.name, name);

	player.ships_count = ships_count;

	return player;
}

void player_destruct(struct Player *player)
{
	field_destruct(player.field);
	free(player.name);

	free(player);
}
