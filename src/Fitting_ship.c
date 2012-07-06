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
			map->field[fitt_ship->top][i].ship = ship;
	else
		for (i = fitt_ship->top; i < fitt_ship->top + 
				fitt_ship->length; i++)
			map->field[i][fitt_ship->left].ship = ship;
	return 0;
}

int check_fitting_cell(const struct Field *map, int left, int top){
	if ((left >= 0) && (left < map->width) &&
			(top >= 0) && (top < map->height)){
		if (map->field[top][left].ship == NULL) 
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

int check_fitting_cells(const struct Field *map, int left, int top){
	if (check_fitting_cell(map, left, top) == 0)
		return 0;
	if (check_fitting_cell(map, left - 1, top - 1) == 0)
		return 0;
	if (check_fitting_cell(map, left, top-1) == 0)
		return 0;
	if (check_fitting_cell(map, left + 1, top - 1) == 0)
		return 0;
	if (check_fitting_cell(map, left + 1, top) == 0)
		return 0;
	if (check_fitting_cell(map, left + 1, top + 1) == 0)
		return 0;
	if (check_fitting_cell(map, left, top + 1) == 0)
		return 0;
	if (check_fitting_cell(map, left - 1, top + 1) == 0)
		return 0;
	if (check_fitting_cell(map, left - 1, top) == 0)
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

int fitting_ship(const struct Field *map, struct Fitting_ship *fitt_ship){
	int i;
	fitt_ship->check_fitting_permit = 1;
	if (fitt_ship->orient == horizontal){
		if (fitt_ship->left + fitt_ship->length <= map->width){	
			for (i = fitt_ship->left; i < fitt_ship->left + 
					fitt_ship->length; i++){
				if (check_fitting_cells(map, i, fitt_ship->top) == 0)
					fitt_ship->check_fitting_permit = 0;
			}
		}
		else
			fitt_ship->check_fitting_permit = 0;
	}
	else
		if (fitt_ship->top + fitt_ship->length <= map->height){
			for (i = fitt_ship->top; i < fitt_ship->top + 
					fitt_ship->length; i++){
				if (check_fitting_cells(map, fitt_ship->left, i) == 0)
					fitt_ship->check_fitting_permit = 0;
			}
		}
		else
			fitt_ship->check_fitting_permit = 0;
	return fitt_ship->check_fitting_permit;
}
