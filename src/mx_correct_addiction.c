#include "pathfinder.h"

static void int_check(char **str, int i);
static void pr_int_error(int i);
static void next_check(int i, char **str);
static void char_check(char **str, int i);

void mx_correct_addiction(char **str) {
	int count = 0;
	
	for (int i = 0; str[i] != NULL; i++) {
		count = 0;
		for (int j = 0; j < mx_strlen(str[i]); j++) {
			if (str[i][j] == '-' || str[i][j] == ',')
				count++;
		}
		next_check(i, str);
		if (count != 2) 
			pr_int_error(i);
		int_check(str, i);
		char_check(str, i);
	}
}
static void next_check(int i, char **str) {
	int count = 0;

	for (int j = 0; str[i][j]; j++) {
		if (str[i][j] == '-')
			count++;
	}
	if (count == 2)
		pr_int_error(i);
}

static void char_check(char **str, int i) {
	int j = 0;
	for (;str[i][j] != '-'; j++) {
		if (!mx_is_alpha(str[i][j]))
			pr_int_error(i);
	}
	for (j = j + 1; str[i][j] != ','; j++) {
		if (!mx_is_alpha(str[i][j]))
			pr_int_error(i);
	}
	j = 0;
}

static void int_check(char **str, int i) {
	int count = 0;

	for (int j = 0; str[i][j] != ','; j++)
		count++;
	if (str[i][count + 1] == '\0')
		pr_int_error(i);
	for (int j = count + 1; str[i][j]; j++) {
		if (!mx_is_digit(&str[i][j]))
			pr_int_error(i);
	}
}

static void pr_int_error(int i) {
	char number;

	mx_print_str_error("error: line ");
	number = (i + 2) + '0';
	mx_printerror(number);
	mx_print_str_error(" is not valid");
	write(2, "\n", 1);   
	exit(-1);
}
