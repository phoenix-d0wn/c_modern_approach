//test_compare_str.c

#include "compare_str.h"

int main(void)
{
    bool is_identical = compare_str("Abc", "abc");

    printf("Is identical?: %b\n", is_identical);

    return 0;
}