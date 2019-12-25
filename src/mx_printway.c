#include "pathfinder.h"

static void path(int g, int k, st_main *main);
static void route(int g, int k, st_main *main, st_dks *dks);
static void way_revers(char **way_str);

void mx_printway(st_main *main, int k, int g_size, st_dks *dks) {
	
	char line[49] = "========================================\n";
	int g = k;

	for (; k < g_size; k++) {
		if (k > 0 && dks->vector[k] != 0){
			mx_printstr(line);
			path(g, k, main);
			route(g, k, main, dks);
			mx_printint(dks->vector[k]);
			mx_printstr("\n");
			mx_printstr(line);
		}
	}
}

static void path(int g, int k, st_main *main) {
	char path[7] = "Path: ";

	mx_printstr(path);
	mx_printstr(main->unic[g]);
	mx_printstr(" -> ");
	mx_printstr(main->unic[k]);
	mx_printstr("\n");
}

static void route(int g, int k, st_main *main, st_dks *dks) {
	char route[8] = "Route: ";
	char **way_str = (char**)malloc(sizeof(char**) * 10000);
	int l_ind = k;
	int way = 0;

	mx_printstr(route);
	mx_printstr(main->unic[g]);
	mx_printstr(" -> ");
	for (int j = 0; dks->way[l_ind] != g; j++) {
		way = dks->way[l_ind];
		way_str[j] = (char*)malloc(sizeof(char*) * 200);
		way_str[j] = main->unic[way];
		l_ind = dks->way[l_ind];
	}
	way_revers(way_str);
	mx_printstr(main->unic[k]);
	mx_dis_mass(main, g, k, way_str);
}

static void way_revers(char **way_str) {
	int count = 0;
	char *buf = NULL;

	for (int i = 0; way_str[i]; i++)
		count++;
	if (count > 1) {
		for (int i = 0; i < count - 1; i++) {
			buf = way_str[i];
			way_str[i] = way_str[i + 1];
			way_str[i + 1] = buf;
		}
	}
	for (int i = 0; i < count; ++i) {
		mx_printstr(way_str[i]);
		mx_printstr(" -> ");
	}
}
