#include "pathfinder.h"

void mx_printint_error(int n) {
    if (n == -2147483648) {
        mx_printerror('-');
        mx_print_str_error("214748364");
        mx_printerror('8');
    }
    else {
        if (n < 0) {
            mx_printerror('-');
            n *= -1;
            mx_printint_error(n);
        }
        else if (n > 9) {
            int r = n % 10;
            n /= 10;
            mx_printint_error(n);
            mx_printerror(r + '0');
        }
        else
            mx_printerror(n + '0');
    }
}
