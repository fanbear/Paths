#include "pathfinder.h"

char *mx_read_file(const char *file) {
	r_file *fst = (r_file*)malloc(sizeof(r_file*));
	char buf[512];
	char *temp = NULL;
	char *buf_str = NULL;

	fst->desc = open(file, O_RDONLY);
	if (fst->desc < 0)
		return 0;
	while ((fst->s_read = read(fst->desc, buf, sizeof(char *))) > 0){
		buf[fst->s_read] = '\0';
		fst->s_file += fst->s_read;
		buf_str = mx_strjoin(temp, buf);
		mx_strdel(&temp);
		temp = mx_strdup(buf_str);
		mx_strdel(&buf_str);
	}
	if (close(fst->desc) < 0)
		return 0;
	return temp;
}
