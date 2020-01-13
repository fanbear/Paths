#include "pathfinder.h"

static void cirlce(st_main *main, int i, int j, int n);

char **mx_unic_arr(st_main *main, int size) {
	int count = 0;
	int n = 0;

	main->unic_temp = (char**)malloc(sizeof(char**) * 1000000);
	for (int i = 0, j = 0; main->g_mass[i] != NULL; i++) {
		main->unic_temp[n] = (char*)malloc(sizeof(char*) * 20000);	
		for (;main->g_mass[i][j] != '-'; j++)
			count++;
		mx_strncpy(main->unic_temp[n], main->g_mass[i], count);
		n++;
		main->unic_temp[n] = (char*)malloc(sizeof(char*) * 200000);
		j += 1;
		count = 0;
		cirlce(main, i, j, n);
		n++;
		j = 0;
	}
	main->unic_temp[n + 1] = NULL;
	main->unic_temp = mx_del_dublicate(main->unic_temp, size);
	return main->unic_temp;
}

static void cirlce(st_main *main, int i, int j, int n) {
	int c = 0;

	while (main->g_mass[i][j] != ',') {
		main->unic_temp[n][c] = main->g_mass[i][j];
		j++;
		c++;
	}
}
