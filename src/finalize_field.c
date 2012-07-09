#include <stdlib.h>
#include "seabattle_utils.h"

int finalize_field(struct Player* gamer){
	int i, j;
	for (i = 0; i < gamer->field->width; i++)
		for (j = 0; j < gamer->field->height; j++)
			shot(gamer, j, i, NULL, NULL, NULL);
	return 0;
}
