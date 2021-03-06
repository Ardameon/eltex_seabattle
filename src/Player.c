#include <stdlib.h>
#include <string.h>

#include "Player.h"

struct Player *player_construct(struct Config *config, const char *name,
	int ships_count)
{
	struct Player *player;

	if (config == NULL || name == NULL)
		return NULL;

	if ((player = malloc(sizeof(*player))) == NULL)
		return NULL;

	if ((player->field = field_construct(config)) == NULL) {
		free(player);

		return NULL;
	}

	player->name = calloc(strlen(name) + 1, sizeof(*(player->name)));
	
	if (player->name == NULL) {
		free(player->field);
		free(player);

		return NULL;
	}

	strcpy(player->name, name);

	player->ships_count = ships_count;

	return player;
}

void player_destruct(struct Player *player)
{
	field_destruct(player->field);
	free(player->name);

	free(player);
}
