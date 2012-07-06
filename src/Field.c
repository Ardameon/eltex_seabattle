#include <stdlib.h>

#include "Field.h"

struct Field *field_construct(struct Config *config)
{
	struct Field *field;
	int i;

	if ((field = malloc(sizeof(*field))) == NULL)
		return NULL;

	field->width = conf->field_width;
	field->height = conf->field_height;
	field->field = malloc(field->height * sizeof(*filed->field));

	if (field->field == NULL) {
		free(field);

		return NULL;
	}

	for (i = 0; i < field->height; ++i) {
		field->field[i] = calloc(field->width, sizeof(**field->field));

		if (field->field[i] == NULL) {
			while (--i >= 0)
				free(field->field[i]);

			free(field->field);

			free(field);

			return NULL;
		}
	}

	return field;
}

void field_destruct(struct Field *field)
{
	int i;

	for (i = 0; i < field->height; ++i)
		free(field->field[i]);

	free(field->field);

	free(field);
}
