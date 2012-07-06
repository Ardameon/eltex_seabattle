#include "UI.h"
#include <stdlib.h>

char *input_name(void)
{
	char *name = malloc(sizeof(char) * 2);
	name[0] = 'x';
	name[1] = '\0';
	return name;
}
