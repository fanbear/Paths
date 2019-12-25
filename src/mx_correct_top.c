#include "pathfinder.h"

static void corect_endfile(char *str);
static void pr_int_error(int i);
static void corect_beginfile(char *s);

void mx_correct_top(char *s) {
	char *vertix = (char*)malloc(sizeof(char*));
	int i = 0;

	while (s[i] != '\n') {
		vertix[i] = s[i];
		i++;
	}
	vertix[i + 1] = '\0';
	if (mx_is_digit(vertix) == false) {
		mx_print_str_error("error: line 1 is not valid");
		mx_printerror('\n');
		free(vertix);
		exit(-1);
	}
	corect_beginfile(s);
	corect_endfile(s);
	free(vertix);
}

static void corect_beginfile(char *s) {
	if (s[0] == '\0' || s[0] == '\n') {
		mx_print_str_error("error: line 1 is not valid");
		mx_printerror('\n');
		exit(-1);
	}
}

static void corect_endfile(char *str) {
	int len = mx_strlen(str);
	int count = 0;

	for (int j = 0; str[j]; j++) {
		if (str[j] == '\n')
			count++;
	}
	if (str[len - 1] != '\n')
		pr_int_error(count - 1);
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
