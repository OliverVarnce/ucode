#include "libmx.h"

bool mx_isalpha(int c) {
    if ((c > 65 && c < 90) || (c > 96 && c < 123))
        return 1;
    else
	    return 0;
}
