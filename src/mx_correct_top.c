#include "pathfinder.h"

static void corect_endfile(char *str);
static void pr_int_error(int i);
static void corect_beginfile(char *s);

void mx_correct_top(char *s) {
	char *vertix = (char*)malloc(sizeof(char*));
	int count = 0;

	for (int i = 0; s[i] != '\n'; i++){
		vertix[i] = s[i];
		count++;
	}
	vertix[count] = '\0';
	if (!mx_is_digit(vertix)) {
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
	mx_print_str_error("error: line ");
	mx_printint_error(i + 2);
	mx_print_str_error(" is not valid");
	write(2, "\n", 1);   
	exit(-1);
}
