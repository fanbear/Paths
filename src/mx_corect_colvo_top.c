#include "pathfinder.h"

void mx_corect_colvo_top(char **temp, int size) {
	int count = 0;

	for (int i = 0; temp[i] != NULL; i++)
		count++;
	if (count != size) {
		mx_print_str_error("error: invalid number of islands");
		mx_printerror('\n');
		exit(-1);
	}
}
