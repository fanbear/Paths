#ifndef PATHFINDER_H
#define PATHFINDER_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "libmx/inc/libmx.h"

#define Line "========================================\n"
#define NEW_LINE "\n"
#define ARROW " -> "
#define PLUS " + "
#define EQUALITY " = "
#define EMPTY_LINE ""
//***************************** Utils pack *******************************


typedef struct file{
	int desc;
	int s_read;
	int s_file ;
	
} r_file;

typedef struct main{
	char *str_file;
	char **g_mass;
	char **o_graf;
	char **unic;
	int **matrix;
	int *stf;
	int k;
	char **unic_temp;
	int g_size;

} st_main;

typedef struct dks{
	int *vector; // строка интов минимальный путей
	int min; //минимальное значение пути в матрице смежности
	int min_index; //индекс минимального значения пути
	bool flag;
	int **path;
	
} st_dks;

typedef struct route{
	int *route;
	int size;
	int count;

} st_route;

void mx_arg_error(int argc, char *file);
bool mx_is_digit(char *c);
bool mx_is_alpha(char c);
char *mx_read_file(const char *file);
char **mx_str_to_mas(char *str);                                                                         
void mx_correct_addiction(char **str);
void mx_correct_top(char *s);
void mx_print_str_error(char *s);
void mx_printerror(char s);
char **mx_unic_arr(st_main *main, int size); 
char **mx_del_dublicate(char **str, int size); 
void mx_corect_colvo_top(char **temp, int size); // проверка на соотвецтвие кол-ва уникальных вершин
char **mx_graf_addiction(st_main *main); // разбития грава на строки типа (первая, вторая, путь!)
int **mx_matrix_adj(char **graf, char **unic, int size); // матрица смежности вершин
int mx_int_point(char **unic, char *delim); // Возвращает индекс после сравнения данных в масиве путей с масивом уникальных вершин.
void mx_full_matrix(int **matrix, int x, int y, int way); // заполняет путь в матрице;
int *mx_smej(int size, int top);
int mx_vector_min(int *str, int size, int *stf);
void mx_dekstra(st_main *main, int g_size);
int *mx_f_str(int **mass, int size, int v);
int mx_min_index(int *vector, int min, int size, int *str);
int mx_atoi(const char *str);
void mx_dis_mass(st_main *main, int g, int k, char **way_str);
void mx_printint_error(int n);
void mx_output(st_main *main, st_dks *dks, int begin, int end);
void mx_destroy_null(int** matrix, int count);
void mx_btrack(st_main *main, st_dks *dks, st_route *route);


//-----------------------------------------------------------------------                                       

#endif
