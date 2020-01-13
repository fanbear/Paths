#include "pathfinder.h"

char **mx_str_to_mas(char *str)
{
	char **buf = (char **)malloc(sizeof(char **) * 4000);
	int f = 0;
	int n = 0;
	int i = 0;

	while (str[f] != '\n')
		f++;
	n = f + 1;
	for (int j = 0; str[n] != '\0'; i++) {
		buf[i] = (char *)malloc(sizeof(char *) * 120000);
		for (j = 0 ;str[n] != '\n'; j++, n++)
			buf[i][j] = str[n];
		buf[i][j] = '\0';
		n += 1;
	}
	buf[i] = NULL;
	return buf;
}
