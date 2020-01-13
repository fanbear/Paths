#include "pathfinder.h"

int *mx_f_str(int **mass, int size, int v) {
	int *temp = (int *)malloc(sizeof(int*) * 10000);

	for (int i = 0; i < size; i++)
		temp[i] = mass[v][i];
	return temp;
}
