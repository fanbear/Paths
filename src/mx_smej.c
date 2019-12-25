#include "pathfinder.h"

int *mx_smej(int size, int top) {
	int *temp = (int *)malloc(sizeof(int*) * 200);
	
	for (int i = 0; i < size; i++)
		temp[i] = top;
	return temp;
}
