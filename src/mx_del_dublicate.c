#include "pathfinder.h"

char **mx_del_dublicate(char **str, int size) {
	char **temp = (char**)malloc(sizeof(char**) * 2000000);
	int n = 0;

	temp[0] = malloc(sizeof(char*) * 200);
	mx_strncpy(temp[n], str[n], mx_strlen(str[n]));
	for (int i = 0, flag = 0; str[i]; i++) {
		flag = 0;
		for (int j = 0; temp[j]; j++) {
			if (mx_strcmp(str[i], temp[j]) == 0)
				flag = 1;
		}
		if (flag == 0) {
			n++;
			temp[n] = malloc(sizeof(char*) * 200);
			mx_strncpy(temp[n], str[i], mx_strlen(str[i]));
		}
	}
	mx_del_strarr(&str);
	mx_corect_colvo_top(temp, size);
	return temp;
}
