NAME = pathfinder

INC = ./inc/libmx.h

HEADTMP = ./libmx.h

SRC = 	./main.c \
		./mx_printerr.c \
		./mx_printerrmess.c \
		./mx_filereader.c \
		./mx_check_numofislds.c \
		./mx_read_args.c \
		./mx_start_isld.c \
		./mx_finish_isld.c \
		./mx_get_index_char.c \
		./mx_linechecker.c \
		./mx_matrix.c \
		./mx_create_matrix.c \
		./mx_get_num_cpl.c \
		./mx_floyd_alg.c \
		./mx_general_router.c \
		./mx_result_printer.c \
		./mx_file_printer.c \
		./mx_render_out.c \
		./mx_matrixbuilder.c \
		./mx_distance_out.c \
		./mx_count_steps.c
		
SRCS = 	./src/main.c \
		./src/mx_printerr.c \
		./src/mx_printerrmess.c \
		./src/mx_filereader.c \
		./src/mx_check_numofislds.c \
		./src/mx_get_index_char.c \
		./src/mx_read_args.c \
		./src/mx_start_isld.c \
		./src/mx_finish_isld.c \
		./src/mx_linechecker.c \
		./src/mx_matrix.c \
		./src/mx_create_matrix.c \
		./src/mx_get_num_cpl.c \
		./src/mx_floyd_alg.c \
		./src/mx_general_router.c \
		./src/mx_result_printer.c \
		./src/mx_file_printer.c \
		./src/mx_render_out.c \
		./src/mx_matrixbuilder.c \
		./src/mx_distance_out.c \
		./src/mx_count_steps.c
		

OBJ = 	./main.o \
		./mx_printerr.o \
		./mx_printerrmess.o \
		./mx_filereader.o \
		./mx_check_numofislds.o \
		./mx_read_args.o \
		./mx_start_isld.o \
		./mx_finish_isld.o \
		./mx_get_index_char.o \
		./mx_linechecker.o \
		./mx_matrix.o \
		./mx_create_matrix.o \
		./mx_get_num_cpl.o \
		./mx_floyd_alg.o \
		./mx_general_router.o \
		./mx_result_printer.o \
		./mx_file_printer.o \
		./mx_render_out.o \
		./mx_matrixbuilder.o \
		./mx_distance_out.o \
		./mx_count_steps.o
		

OBJO = 	./obj/main.o \
		./obj/mx_printerr.o \
		./obj/mx_printerrmess.o \
		./obj/mx_filereader.o \
		./obj/mx_check_numofislds.o \
		./obj/mx_read_args.o \
		./obj/mx_start_isld.o \
		./obj/mx_finish_isld.o \
		./obj/mx_get_index_char.o \
		./obj/mx_linechecker.o \
		./obj/mx_matrix.o \
		./obj/mx_create_matrix.o \
		./obj/mx_get_num_cpl.o \
		./obj/mx_floyd_alg.o \
		./obj/mx_general_router.o \
		./obj/mx_result_printer.o \
		./obj/mx_file_printer.o \
		./obj/mx_render_out.o \
		./obj/mx_matrixbuilder.o \
		./obj/mx_distance_out.o \
		./obj/mx_count_steps.o

		
	
CFLGS = -std=c11 -Wall -Wextra -Wpedantic -Werror 

all: install uninstall
install:
	@cd libmx && make -f Makefile all
	@cp $(INC) $(SRCS) .
	@clang $(CFLGS) -c  $(SRC)
	@mkdir  obj
	@mv $(OBJ) ./obj
	@clang $(CFLGS) $(OBJO) libmx/libmx.a -o $(NAME)
uninstall:
	@cd libmx && make -f Makefile uninstall
	@rm -rf $(OBJO) $(SRC) $(HEADTMP)
	@rm -rf ./obj
clean: uninstall
	@cd libmx && make -f Makefile clean
	@rm -rf $(NAME)
reinstall: clean all