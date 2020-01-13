#include "pathfinder.h"

static void add_int(int **temp, int size);
static void m_fun(char **graf, char** unic, int size, int **temp);

int **mx_matrix_adj(char **graf, char **unic, int size) {
	int** temp = (int**)malloc(1000000 * sizeof(int**));

	add_int(temp, size);
	m_fun(graf, unic, size, temp);
	return temp;
}

static void add_int(int **temp, int size) {
	for (int i = 0; i < size; i++) {
		temp[i] = (int*) malloc(40000 * sizeof(int*));
		for (int j = 0; j < size; j++)
			temp[i][j] = 0;
	}
}

static void m_fun(char **graf, char** unic, int size, int **temp) {
	int x = 0;
	int y = 0;
	int count = 0;
	int i = 0;
	int j = 0;

	for (; graf[i] != NULL; i++)
		count++;
	for (i = 0; i < count; i++) {
		for (j = 0; j < size; j++) { 
			if (mx_strcmp(graf[i], unic[j]) == 0)
				x = mx_int_point(unic, unic[j]);
		}
		for (j = 0; j < size; j++) {
			if (mx_strcmp(graf[i + 1], unic[j]) == 0)
				y = mx_int_point(unic, unic[j]);
		}
		mx_full_matrix(temp, x, y, mx_atoi(graf[i + 2]));
		i += 2;
	}
}
