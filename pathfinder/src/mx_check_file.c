#include "pathfinder.h"

static void is_empty(char **argv);
static void is_folder(char **argv);
static void is_not_exist(char **argv);

bool mx_check_file(t_main *main) {
    if (main->argc != 2) {
        mx_printerr(ERROR_USAGE);
        exit (0);
    }
	is_not_exist(main->argv);
	is_folder(main->argv);
	is_empty(main->argv);
	return true;
}

static void is_empty(char **argv) {
    int fd = open(argv[1], O_RDONLY);
    char buf;
    
	if (read(fd, &buf, 1) == 0) {
		close(fd);
		mx_printerr(EMPTY_FILE_START);
		mx_printerr(argv[1]);
		mx_printerr(EMPTY_FILE_END);
		exit (0);
	}
}

static void is_folder(char **argv) {
	int fd = open(argv[1], O_RDONLY);

	if (read(fd, (void *)0, 0) < 0) {
 	    close(fd);
		mx_printerr(ERROR_USAGE);
	    exit (0);
    }
}

static void is_not_exist(char **argv) {
	int fd = open(argv[1], O_RDONLY);

	if (fd < 0) {
	    close(fd);
	    mx_printerr(FILE_EXIST);
	   	mx_printerr(argv[1]);
	    mx_printerr(FILE_EXIST2);
	    exit (0);
	}
}
