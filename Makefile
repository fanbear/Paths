NAME = pathfinder

INC = pathfinder.h

INCI = inc/pathfinder.h

INCLIB = libmx/libmx.a

SRC = \
mx_arg_error.c \
mx_corect_colvo_top.c \
mx_correct_addiction.c \
mx_correct_top.c \
mx_dekstra.c \
mx_del_dublicate.c \
mx_f_str.c \
mx_full_matrix.c \
mx_graf_addiction.c \
mx_int_point.c \
mx_is_alpha.c \
mx_is_digit.c \
mx_matrix_adj.c \
mx_min_index.c \
mx_print_str_error.c \
mx_printerror.c \
mx_printway.c \
mx_read_file.c \
mx_smej.c \
mx_str_to_mas.c \
mx_unic_arr.c \
mx_vector_min.c \
mx_atoi.c \
mx_dis_mass.c \
mx_printint_error.c \
main.c \


SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install clean

install:
	@make -C libmx
	@cp $(SRCS) .
	@cp $(INCI) .
	@clang $(CFLAGS) -c $(SRC) -I $(INC)
	@clang $(CFLAGS) $(INCLIB) $(OBJ) -o $(NAME)
	@mkdir -p obj
	@mv $(OBJ) ./obj

uninstall: clean
	@rm -rf $(NAME) $(INCLIB)

clean:
	@rm -rf $(SRC) $(OBJ) $(INC)
	@rm -rf ./obj

reinstall: uninstall all
