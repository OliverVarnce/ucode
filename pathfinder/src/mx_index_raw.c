#include "pathfinder.h"

int mx_index_raw(char *str, int count, t_island *p) {
    for (int i = 0; i < count; i++)
    {
        if (mx_strcmp(p[i].name, str) == 0)
            return p[i].index_name;
    }
    return -1;
}
