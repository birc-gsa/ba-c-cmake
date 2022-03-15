#include "gsa.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_RAND_STRING_LEN 100

static void check_is_border(size_t n, const char x[n], int i, int b)
{
    while (b > 0)
    {
        b--;
        i--;
        assert(x[b] == x[i + 1]);
    }
}

static void check_is_strict_border(size_t n, const char x[n], int i, int b)
{
    check_is_border(n, x, i, b);
    assert(b == 0 || i == (int)n - 1 || x[b] != x[i + 1]);
}

static void random_string(size_t n, char x[n], const char *alphabet, int alpha_size)
{
    for (size_t i = 0; i < n; i++)
    {
        x[i] = alphabet[rand() % alpha_size];
    }
}

static void test_border_array(void)
{
    char x[MAX_RAND_STRING_LEN];
    int ba[MAX_RAND_STRING_LEN];
    for (int rep = 0; rep < 10; rep++)
    {
        int len = rand() % MAX_RAND_STRING_LEN;
        random_string(len, x, "acgt", 4);
        border_array(len, x, ba);
        for (int i = 0; i < len; i++)
        {
            check_is_border(len, x, i, ba[i]);
        }
    }
}

static void test_strict_border_array(void)
{
    char x[MAX_RAND_STRING_LEN];
    int ba[MAX_RAND_STRING_LEN];
    for (int rep = 0; rep < 10; rep++)
    {
        int len = rand() % MAX_RAND_STRING_LEN;
        random_string(len, x, "acgt", 4);
        strict_border_array(len, x, ba);
        for (int i = 0; i < len; i++)
        {
            check_is_strict_border(len, x, i, ba[i]);
        }
    }
}

int main(void)
{
    test_border_array();
    test_strict_border_array();
    return 0;
}
