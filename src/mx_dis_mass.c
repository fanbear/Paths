#include "pathfinder.h"

static int ret_int_index(char *str, st_main *main);
static void if_two(int g, int k, st_main *main, char ** way_str);

void mx_dis_mass(st_main *main, int g, int k, char **way_str) {
	int j = 0;
	int count = 0;

	mx_printstr("\n");
	mx_printstr("Distance: ");
	for (int n = 0; way_str[n]; n++)
		count++;
	if (count == 1) {
		j = ret_int_index(way_str[0], main);
		mx_printint(main->matrix[g][j]);
		mx_printstr(" + ");
		mx_printint(main->matrix[j][k]);
		mx_printstr(" = ");
	}
	if (count == 2)
		if_two(g, k, main, way_str);
}

static void if_two(int g, int k, st_main *main, char ** way_str) {
	int ind = g;
	int ind2 = 0;
	int count = 0;

	for (int n = 0; way_str[n]; n++)
		count++;
	for (int i = 0; i < count; ++i) {
		ind2 = ret_int_index(way_str[i], main);
		if (main->matrix[ind][ind2] == 0)
			break;
		mx_printint(main->matrix[ind][ind2]);
		mx_printstr(" + ");
		ind = ind2;
	}
	mx_printint(main->matrix[ind][k]);
	mx_printstr(" = ");
}

static int ret_int_index(char *str, st_main *main) {
	for (int i = 0; main->unic[i]; i++) {
		if (mx_strcmp(str, main->unic[i]) == 0)
			return i;
	}
	return 0;
}
