#include <stdlib.h>
#include "Field.h"

struct Field *field_construct(struct Config *conf){
	struct Field * ptr = malloc (sizeof(struct Field));
	int i,j;
	ptr->width = conf->field_width;
	ptr->height = conf->field_height;
	ptr->field = malloc (ptr->height * sizeof(struct Cell **));
	for (i = 0; i < ptr->height; i++){
		ptr->field[i] = malloc (ptr->width * sizeof(struct Cell *)); 
		for (j = 0; j < ptr->width; j++)
			ptr->field[i][j] = NULL;
	}
	return ptr;
}

void field_destruct(struct Field *field){
	int i;
	for (i = 0; i < field->height; i++)
		free(field->field[i]);
	free(field->field);
}
