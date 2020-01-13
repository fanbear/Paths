#include "pathfinder.h"

int mx_min_index(int *vector, int min, int size, int *stf) {
	int index = 0;
	int flag = 0;
	
	for (int i = 0; i < size; i++) {
		for (int n = 0; n < size; n++) {
			flag = 0;
			if (i == stf[n]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			if (min == vector[i]) {
				index = i;
				return index;
			}
		}
	}
	return index;
}
