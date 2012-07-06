#include <stdlib.h>
#include "Fitting_ship.h"

struct Fitting_ship *fitting_ship_construct(struct Field *map, int rank){
	struct Fitting_ship *ptr = malloc(sizeof(struct Fitting_ship));
	ptr->left = ptr->top = 0;
	ptr->length = rank;
	ptr->orient = horizontal;
	fitting_ship(map, ptr);
	return ptr;
}

int add_ship_on_field(struct Field *map, struct Fitting_ship *fitt_ship){
	int i;
	struct Ship *ship = ship_construct(fitt_ship->length, "TEST NAME");
	if (fitt_ship->orient == horizontal)
		for (i = fitt_ship->left; i < fitt_ship->left + 
				fitt_ship->length; i++)
			map->field[fitt_ship->top][i] = cell_construct(ship);
	else
		for (i = fitt_ship->top; i < fitt_ship->top + 
				fitt_ship->length; i++)
			map->field[i][fitt_ship->left] = cell_construct(ship);
	return 0;
}

int check_fitting_cell(struct Field *map, int left, int top){
	if (map->field[top][left] != 0)
		return 0;
	if ((left != 0) && (map->field[top][left - 1] != NULL))
		return 0;
	if ((left != map->width - 1) && (map->field[top][left + 1] != NULL))
		return 0;
	if ((top != 0) && (map->field[top - 1][left] != NULL))
		return 0;
	if ((top != map->height - 1) && (map->field[top + 1][left] != NULL))
		return 0;
	if ((top != 0) && (left != 0) && 
		(map->field[top - 1][left - 1] != NULL))
		return 0;
	if ((top != map->height - 1) && (left != 0) && 
		(map->field[top + 1][left - 1] != NULL))
		return 0;
	if ((top != 0) && (left != map->width - 1) && 
		(map->field[top - 1][left + 1] != NULL))
		return 0;
	if ((top != map->height - 1) && (left != map->width - 1) && 
		(map->field[top + 1][left + 1] != NULL))
		return 0;
	return 1;
}

int rotation(struct Field *map, struct Fitting_ship *fitt_ship){
	if (fitt_ship->orient == horizontal)
		fitt_ship->orient = vertical;
	else
		fitt_ship->orient = horizontal;
	fitting_ship(map, fitt_ship);
	return 0;
}

int fitting_ship(struct Field *map, struct Fitting_ship *fitt_ship){
	int i;
	fitt_ship->check_fitting_permit = 1;
	if (fitt_ship->orient == horizontal){
		if (fitt_ship->left + fitt_ship->length < map->width){	
			for (i = fitt_ship->left; i < fitt_ship->left + 
					fitt_ship->length; i++){
				if (check_fitting_cell(map, i, fitt_ship->top) == 0)
					fitt_ship->check_fitting_permit = 0;
			}
		}
		else
			fitt_ship->check_fitting_permit = 0;
	}
	else
		if (fitt_ship->top + fitt_ship->length < map->height){
			for (i = fitt_ship->top; i < fitt_ship->top + 
					fitt_ship->length; i++){
				if (check_fitting_cell(map, fitt_ship->left, i) == 0)
					fitt_ship->check_fitting_permit = 0;
			}
		}
		else
			fitt_ship->check_fitting_permit = 0;
	return fitt_ship->check_fitting_permit;
}
