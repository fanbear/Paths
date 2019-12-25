#include "pathfinder.h"

bool mx_is_alpha(char c) {
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return 1;
	return 0;
}
