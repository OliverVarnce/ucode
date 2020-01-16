#include "pathfinder.h"

static void valid_island(char **islArr);
static void range_validator(char **islArr);
static void check_delim(char **islArr);

bool str_is_digit(char *str) {
	for (int i = 0; str[i]; i++) {
		if (!mx_isdigit(str[i]))
			return false;
	}
	return true;
}

void mx_check_fillin(t_file *file) {
	mx_apex_count(file->str);
	mx_island_not_char(file->str);
	mx_double_linebrake(file->file);
	mx_repeat_islands(file->str);
	check_delim(file->str);
	range_validator(file->str);
	valid_island(file->str);
    if (file->count == 0)
        mx_invalid_num_of_islds();
}

static void valid_island(char **islArr) {
	for(int i = 1; islArr[i]; i++) {
		char **str = mx_strsplit(islArr[i], '-');

		if (str[0] == NULL || mx_arrlen(str) < 2) {
			char *num = mx_itoa(i + 1);
			mx_print_erno(num);
			mx_del_strarr(&str);
			exit (0);
		}
		char **str2 = mx_strsplit(str[1], ',');

		if (str2[0] == NULL || mx_arrlen(str2) < 2) {
			char *num = mx_itoa(i + 1);
			mx_print_erno(num);
			mx_del_strarr(&str2);
			exit (0);
		}
		mx_double_del(str, str2);
	}
}

static void range_validator(char **islArr) {
	char *num = NULL;

	for (int i = 1; islArr[i]; i++) {
		char **str = mx_strsplit(islArr[i], ',');

		if (mx_arrlen(str) != 1) {
			if (!str_is_digit(str[1]) || mx_atoi(str[1]) == 0) {
				num = mx_itoa(i + 1);
				mx_printerr(LINE_VALUE_START);
				mx_printerr(num);
				mx_printerr(LINE_VALUE_END);
				exit (0);
			}
		}
		mx_del_strarr(&str);
	}
}

static void check_delim(char **islArr) {
	char minus = '-';
	char zap = ',';
	
	for (int i = 1; islArr[i]; i++) {
		if (mx_char_count(islArr[i], minus) != 1
			|| mx_char_count(islArr[i], zap) != 1) {
			char *num = mx_itoa(i + 1);

			mx_printerr(LINE_VALUE_START);
			mx_printerr(num);
			mx_printerr(LINE_VALUE_END);
			exit (0);
		}
	}
}
