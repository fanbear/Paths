#include "pathfinder.h"

static void point(st_dks *dks, int g_size, st_main *main, int i);
static void dks_alg(st_main *main, int g_size, st_dks *dks, int k);
static void iteration(st_main *main, st_dks *dks, int i, int g_size);
static void dks_condition(st_main *main, st_dks *dks, int k, int j);

void mx_dekstra(st_main *main, int g_size) {
	st_dks *dks = (st_dks*)malloc(sizeof(st_dks*) * 20);

	for (int k = 0; k < g_size - 1; k++) {
		main->stf = mx_smej(g_size, k);
		point(dks, g_size, main, k);
		for (int i = 0; i < g_size; i++) {
			dks->way[i] = k;
		}
		dks_alg(main, g_size, dks, k);
		mx_printway(main, k, g_size, dks);
	}
	free(dks);
}

static void dks_alg(st_main *main, int g_size, st_dks *dks, int k) {	
	main->stf[0] = k;
	for (int i = 0; i < g_size - 1; i++) {
		for (int j = 0; j < g_size; j++) {
			dks->flag = 0;
			for (int n = 0; n < g_size; n++) {
				if (j == main->stf[n]) {
					dks->flag = 1;
					break;
				}
			}
			dks_condition(main, dks, k, j);
		}
		iteration(main, dks, i, g_size);
		k = dks->min_index;
	}
}

static void dks_condition(st_main *main, st_dks *dks, int k, int j) {
	int token = 0;
	bool check = 0;

	if (dks->flag == 0) {
		token = dks->min + main->matrix[k][j];
		if (token < dks->vector[j] || dks->vector[j] == 0)
			check = 1;
		if (check == 1 && main->matrix[k][j] > 0) {
			dks->vector[j] =  dks->min + main->matrix[k][j];
			dks->way[j] = dks->min_index;
		}
	}
}

static void iteration(st_main *main, st_dks *dks, int i, int g_size) {		
	dks->min = mx_vector_min(dks->vector, g_size, main->stf);
	dks->min_index = mx_min_index(dks->vector, dks->min, g_size);
	main->stf[i + 1] = dks->min_index;
}

static void point(st_dks *dks, int g_size, st_main *main, int i) {
	dks->vector = mx_f_str(main->matrix, g_size, i);
	dks->min = mx_vector_min(dks->vector, g_size, main->stf);
	dks->min_index = mx_min_index(dks->vector, dks->min, g_size);
	dks->way = (int*)malloc(sizeof(int*) * 100000);
}
