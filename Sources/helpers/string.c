#include "../../Headers/helpers/string.h"

int     str_to_int(const char * s)
{
    int i;
    int v;

    if (s[0] == '-') return 0;
    for(i = 0, v = 0; s[i] >= 48 && s[i] <= 57 && s[i] != '\0'; ++i) {
        v = v * 10 + s[i] - 48;
        if (v > 65534) return 0;
    }
    return v;
}
