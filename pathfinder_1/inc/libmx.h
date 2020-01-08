#ifndef __LIBMX_H__
#define __LIBMX_H__

#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>
#include <memory.h>
#include <fcntl.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

typedef enum e_error {
    INVALID_ARGS,
    FILE_DNT_EXIST,
    FILE_EMPTY,
    INVALID_FIRST_LINE,
    INVALID_LINE,
    INVALID_NUM_ISLANDS
} t_error;

typedef struct s_construct {
    int size;
    int **matrix;
    int **dist;
    char **top;
    char **file; //file to print
} t_construct;

typedef struct s_adj_list_node {
    int dest;
    struct s_adj_list_node *next;
} t_adj_list_node;

typedef struct s_adj_list {
    struct s_adj_list_node *head;
} t_adj_list;

typedef struct s_graph {
    int V;
    struct s_adj_list *array;
} t_graph;

t_adj_list_node *mx_new_adj_list_node(int dest);
t_graph *mx_create_graph(int V);

/*------ Pathfinder -------*/
void mx_printerrmess(t_error err, const char *comment);
void mx_printerror(const char *error);
char **mx_filereader(char **argv);
void mx_check_numofislds(char *str);
void mx_start_isld(char *str, char **result, int *n);
void mx_finish_isld(char *str, char **result, int *n);
void mx_firstisld(char *str, char **result, int *n);
void mx_secondisld(char *str, char **result, int *n);
char **mx_read_args(char **str, int size);
bool mx_linechecker(char *str, int line);
int mx_get_index_char(const char *str, char c);
int **mx_matrix(char **top, char **str, int size);
int **mx_create_matrix(int s);
int mx_get_num_cpl(char *isl);
int **mx_floyd_alg(int **matrix, int s);
int **mx_matrixbuilder(t_construct *d, int num);
/*int next_top(t_construct *data, int from, int to, int paths);
int previos_top(t_construct *data, int from, int to);*/
int **mx_general_router(t_construct *d, int num, int from, int to);
int mx_count_steps(t_construct *d, int a, int b);
char **mx_filereader(char **argv);
char **mx_file_printer(t_construct *d, int **path, int num);
void mx_render_out(t_construct *d, int *path, int i, int j);
void mx_distance_out(t_construct *d, int *path, int i, int j);
void mx_result_printer(t_construct *d);
/*---------- END Pathfinder -----------*/


/*------ Utils Pack -------*/
int mx_atoi(const char *str);
int mx_arr_size(char **arr);
void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);
/*---------- END Utils Pack -----------*/

/*---------- String pack --------------*/
int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line (char **lineptr, int buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
bool mx_isdigit(char c);
char *mx_strsub(char const *s, unsigned int start, size_t len);
bool mx_isspace(char c);
bool mx_isalpha(int c);
char *mx_freez(int buf_size, char delim, const int fd);
void mx_swap_char(char *s1, char *s2);
char *mx_strchr(const char *s, int c);

/*---------------- END String pack --------------*/

/*---------------- Memory pack --------------------*/
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);
/*------------ END Memory pack ---------*/

/*------------ List pack ---------------*/
t_list  *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));
/*------------ END List pack ---------------*/

void mx_printerrmess(t_error err, const char *comment);
bool mx_parse_text(char *text);

#endif
