#ifndef PATHFINDER_H
#define PATHFINDER_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>
#include "../libmx/inc/libmx.h"

typedef struct s_main {
    int argc;
    char **argv;
} t_main;

typedef struct s_file {
    char *file;
    char **str;
    int count;
} t_file;

typedef struct s_dist {
	char *point;
	int index_point;
	unsigned int dist;
} t_dist;

typedef struct  s_island {
	char *name;
	int index_name;
	int	routes_count;
	struct s_dist *d;
} t_island;

typedef struct s_result {
	int *way;
	int *way_dist;
	int dist;
	int count;
	struct s_result *next;
} t_result;

#define ERROR_USAGE "usage: ./pathfinder [filename]\n"
#define FILE_EXIST "error: file "
#define FILE_EXIST2 " does not exist\n"
#define EMPTY_FILE_START "error: file "
#define EMPTY_FILE_END " is empty\n"
#define LINE_ERROR "error: line 1 is not valid\n"
#define LINE_VALUE_START "error: line "
#define LINE_VALUE_END " is not valid\n"
#define INVALID_ISLANDS "error: invalid number of islands\n"

void mx_calc_paths(t_island *isl, t_result **lst, t_result **res, t_file *file);
void mx_parse_distance_isl(t_island *isl, t_file *file);
void mx_repeat_islands(char **str);
t_result *mx_create_result(int *way, int count, int *way_dist, int dist);
void mx_pop_front_result(t_result **head);
void mx_push_back_res(t_result **list, int *way, int count, int *way_dist, int dist);
void mx_push_front_result(t_result **list, int *way, int count, int *way_dist, int dist);
int mx_list_size_res(t_result *list);
void mx_swap_el_int(int **s1, int **s2);
void mx_swap_int(int *a, int *b);
void mx_swap_islds(t_result *lst);
t_result *mx_sort_list_result(t_result *lst);
int mx_find_dex(t_result *lst);
void mx_pop_back_res(t_result **head);
void del_el_list(t_result *tmp);
void mx_pop_elem_of_list(t_result *lst);
t_result *mx_create_first_itter_list(t_island *p, int i);
bool mx_repeat_value(int *way, int k, int count);
void mx_create_res_active_island(t_result *lst, t_island p, bool *active_islands);
void mx_res_empty(t_result *res);
t_result *mx_algorithm(t_island *p, t_result *l, int count, int itter);
void mx_double_del(char **s1, char **s2);
void mx_parse_dist(t_island *p, char *f, int count, char **str);
void mx_invalid_num_of_islds();
void mx_parse_islands(t_island *p, char **str, int count);
void mx_print_route(t_result *lst, t_island *p, int count, int i);
void mx_print_num(t_result *lst);
void mx_print_dist(t_result *lst);
void mx_print_result(t_result *lst, t_island *p, int count);
void mx_sort_paths_by_size(t_result *lst);
void mx_sort_paths_by_bounces(t_result *lst);
void mx_sort_paths_by_fifo(t_result *lst);
void mx_check_fillin(t_file *file);
void mx_apex_count(char **islArr);
void mx_print_erno(char *num);
void mx_island_not_char(char **str);
void mx_double_linebrake(char *f);
int mx_index_raw(char *str, int count, t_island *p);
void mx_print_route(t_result *lst, t_island *p, int count, int i);
void mx_print_num(t_result *lst);
void mx_print_result(t_result *lst, t_island *p, int count);
void mx_print_paths(t_result **res, t_island *p, int count);
bool mx_check_file(t_main *main);
bool str_is_digit(char *str);
void mx_print_ends();

/*==========================================================*/


#endif
