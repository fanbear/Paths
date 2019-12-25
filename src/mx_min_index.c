#include "pathfinder.h"

int mx_min_index(int *vector, int min, int size) {
	int index = 0;
	
	for (int i = 0; i < size; i++) {
		if (min == vector[i]) {
			index = i;
			return index;
		}
	}
	return index;
}
