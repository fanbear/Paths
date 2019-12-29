#include "pathfinder.h"

bool mx_is_digit(char *c) {
	for (int i = 0; c[i]; i++) {
		if (c[i] < 48 || c[i] > 57)
			return false;
	}
	return true;
}
