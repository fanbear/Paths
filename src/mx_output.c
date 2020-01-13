#include "pathfinder.h"

static int* mem_int_arr(int count);
static st_route *new_route(st_main *main, int begin, int end);

void mx_output(st_main *main, st_dks *dks, int begin, int end) {
	st_route *route = new_route(main, begin, end);

	mx_btrack(main, dks, route);
}

static st_route *new_route(st_main *main, int begin, int end) {
	st_route *rt = (st_route*)malloc(sizeof(st_route));

	if(rt == NULL)
		exit(-1);	
	rt->route = mem_int_arr(main->g_size);
	rt->size = 1;
	rt->count = main->g_size;
	rt->route[0] = end;
	rt->route[1] = begin;
	return rt;
}

static int* mem_int_arr(int count) {
	int* array = ((int*)malloc(sizeof(int) * count));
	int j = 0;

	for(; j < count; j++) {
		array[j] = 0;
	}
	return array;
}
