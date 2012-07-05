#include <stdlib.h>

#include "Field.h"

struct Field *field_construct(int width, int height)
{
	struct Field *field;
	int i;

	if ((field = malloc(sizeof(*field))) == NULL)
		return NULL;

	field.width = width;
	field.height = height;
	
	if ((field.field = malloc(height * sizeof(*field.field))) == NULL) {
		free(field);

		return NULL;
	}

	for (i = 0; i < height; ++i) {
		field.field[i] = calloc(width, sizeof(**field.field));

		if (field.field[i] == NULL) {
			while (--i >= 0)
				free(field.field[i]);

			free(field.field);
			free(field);

			return NULL;
		}
	}

	return field;
}

void field_destruct(struct Field *field)
{
	int i;

	for (i = 0; i < field.height; ++i)
		free(field.field[i]);

	free(field.field);
	free(field);
}
