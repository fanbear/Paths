#include "pathfinder.h"

int mx_vector_min(int *str, int size, int *stf) {
	int min = 2147483646;
	bool flag = 0;

	for (int i = 0; i < size; i++) {
		for (int n = 0; n < size; n++) {
			flag = 0;
			if (i == stf[n]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			if (min >= str[i] && str[i] != 0) {
				min = str[i];
			}
		}
	}
	return min;
}
