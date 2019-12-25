#include "pathfinder.h"

int mx_vector_min(int *str, int size, int *stf) {
	int min = 0;
	bool flag = 0;

	for (int i = 0; i < size; i++) {
		flag = 0;
		for (int n = 0; n < size; n++) {
			if (i == stf[n]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			if ((min >= str[i] && min == 0) || str[i] != 0 ) 
				min = str[i];
		}
	}
	return min;
}
