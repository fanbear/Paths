#include "pathfinder.h"

int main(int argc, char *argv[]) {
	st_main *main_st = (st_main*)malloc(sizeof(st_main*) * 20);

	mx_arg_error(argc, argv[1]);
	main_st->str_file = mx_read_file(argv[1]);
	mx_correct_top(main_st->str_file);
	int g_size = mx_atoi(main_st->str_file);
	main_st->g_size = g_size;
	main_st->g_mass = mx_str_to_mas(main_st->str_file);
	mx_correct_addiction(main_st->g_mass);
	main_st->unic = mx_unic_arr(main_st, g_size);
	main_st->o_graf = mx_graf_addiction(main_st);
	main_st->matrix = mx_matrix_adj(main_st->o_graf, main_st->unic, g_size);
	mx_dekstra(main_st, g_size);
	free(main_st);
	// system("leaks -q main");
}
