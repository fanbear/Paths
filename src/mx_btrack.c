#include "pathfinder.h"

static int check_nb(int n, st_main *main, st_dks *dks, st_route *route);
static void pr_route(st_main *main, st_route *route);
static void pr_all(st_main *main, st_route *route, st_dks *dks);
static void pr_distance(st_route *route, st_dks *dks);

void mx_btrack(st_main *main, st_dks *dks, st_route *route) {
	if (route->route[route->size] == route->route[0])
    	pr_all(main, route, dks);
	else {
		for (int i = 0; i < main->g_size; i++) {
			if(check_nb(i, main, dks, route)) {
				if (route->size < route->count) {
					route->size++;
					route->route[route->size] = i;
				}
				mx_btrack(main, dks, route);
				if(route->size > 1)
					route->size--;
			}
		}
	}
}

static int check_nb(int n, st_main *main, st_dks *dks, st_route *route) {
	int i = route->route[route->size];
	int j = route->route[0];

	if (i != n) {
		if (main->matrix[i][n] == dks->path[j][i] - dks->path[j][n])
			return 1;
	}
	return 0;
}

static void pr_route(st_main *main, st_route *route) {
	for (int i = 1; i <= route->size; i++){
		mx_printstr(main->unic[route->route[i]]);
		if (i < route->size)
			mx_printstr(ARROW);
		else
			mx_printstr(NEW_LINE);
	}
}

static void pr_distance(st_route *route, st_dks *dks) {
    int sum = 0;
    int n = route->size;

    mx_printstr("Distance: ");
    if (n == 2)
        mx_printint(dks->path[route->route[n]][route->route[n - 1]]);
    else {
        for (int i = 1; i < n; i++) {
            mx_printint(dks->path[route->route[i]][route->route[i + 1]]);
            sum += dks->path[route->route[i]][route->route[i + 1]];            
            if (i + 1 < n)
            	mx_printstr(PLUS);
            else
            	mx_printstr(EMPTY_LINE);
        }
        mx_printstr(EQUALITY);
        mx_printint(sum);
    }
}
static void pr_all(st_main *main, st_route *route, st_dks *dks) {
	mx_printstr(Line);
	mx_printstr("Path: ");
	mx_printstr(main->unic[route->route[1]]);
  	mx_printstr(ARROW);
	mx_printstr(main->unic[route->route[0]]);
	mx_printstr(NEW_LINE);
	mx_printstr("Route: ");
	pr_route(main,route);
	pr_distance(route, dks);
	mx_printstr(NEW_LINE);
	mx_printstr(Line);
}
