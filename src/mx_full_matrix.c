#include "pathfinder.h"

void mx_full_matrix(int **matrix, int x, int y, int way) {
	matrix[x][y] = way;
	matrix[y][x] = way;
}
