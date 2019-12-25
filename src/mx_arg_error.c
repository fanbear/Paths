#include "pathfinder.h"

static void argc_error(int argc);

void mx_arg_error(int argc, char *file) {
	int desc = 0;
	int buf[1024];
	int n = 0;

	argc_error(argc);
	desc = open(file, O_RDONLY); 
	if (desc < 0) {
		mx_print_str_error("error: file ");
		mx_print_str_error(file);
		mx_print_str_error(" does not exist");
		mx_printerror('\n');
		exit(-1);
	}
	if ((n = read(desc,buf,1)) == 0) {
		mx_print_str_error("error: file empty is empty");
		mx_printerror('\n');
		exit(-1);
	}
	close(desc);
}

static void argc_error(int argc) {
	if (argc != 2){
		mx_print_str_error("usage: ./pathfinder [filename]");
		mx_printerror('\n');
		exit(-1);
	}
}
