#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	int i = 0;

	if (arr != NULL && delim != NULL) {
		while (arr[i] != NULL) {
			mx_printstr(arr[i]);
			if (arr[i] != NULL)
				mx_printstr(delim);
			i++;
		}
		write(1, "\n", 1);
	}
}
