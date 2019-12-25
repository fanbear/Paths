#include "pathfinder.h"

static void set_size(st_main *main, char **temp);

char **mx_graf_addiction(st_main *main) {
	char **temp = (char**)malloc(sizeof(char**) * 1024);
	int j = 0;
	int n = 0;
	int c = 0; 

	set_size(main, temp);
	for (int i = 0; main->g_mass[i] != NULL; i++) {
		j = 0;
		for (; main->g_mass[i][j] != '-'; j++)
		mx_strncpy(temp[n], main->g_mass[i], j + 1);
		n++;
		for (c = 0, j = j + 1; main->g_mass[i][j] != ','; j++, c++)
			temp[n][c] = main->g_mass[i][j];
		n++;
		for (c = 0, j = j + 1; main->g_mass[i][j] != '\0'; j++, c++)
			temp[n][c] = main->g_mass[i][j];
		n++;
	}
	temp[n] = NULL;
	return temp;
}

static void set_size(st_main *main, char **temp) {
	int count = 0;
	int summ = 0;

	for (int i = 0; main->g_mass[i] != NULL; i++)
		count++;
	summ = count * 3;
	for (int i = 0; i < summ; i++)
		temp[i] = (char*)malloc(sizeof(char*) * 200);
}
