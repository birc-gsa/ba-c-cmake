#include "gsa.h"

void border_array(size_t n, const char x[n], int ba[n])
{
    ba[0] = 0;
    for (size_t i = 1; i < n; ++i)
    {
        int b = ba[i - 1];
        while (b > 0 && x[i] != x[b])
        {
            b = ba[b - 1];
        }
        ba[i] = (x[i] == x[b]) ? b + 1 : 0;
    }
}

void strict_border_array(size_t n, const char x[n], int ba[n])
{
    border_array(n, x, ba);
    for (size_t i = 0; i < n - 1; i++)
    {
        if (ba[i] > 0 && x[ba[i]] == x[i + 1])
        {
            ba[i] = ba[ba[i] - 1];
        }
    }
}
