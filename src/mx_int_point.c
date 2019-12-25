#include "pathfinder.h"

int mx_int_point(char **unic, char *delim) {
	int i = 0;

	for (int j = 0; mx_strcmp(unic[j], delim) != 0; j++)
		i++;
	return i;
}
