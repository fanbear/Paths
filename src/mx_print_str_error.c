#include "pathfinder.h"

void mx_print_str_error(char *s) {
    int len = mx_strlen(s);

    write(2, s, len);
}
