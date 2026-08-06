//ptr_array.c

#include <stdio.h>

#define MAX_ARR_LEN 10

int main(void)
{
    int idx, *ptr, **ptr2;

    //ARRAY OF INTEGERS
    // int i_arr[MAX_ARR_LEN] = {1, 2, 3, 4};

    // printf("Array:");
    // for (ptr = i_arr; *ptr; ptr++)
    //     printf(" %d", *ptr);
    // printf("\n");

    //ARRAY OF POINTERS TO INTEGERS
    int a = 1, b = 2, c = 3, d = 4;
    int *p_arr[MAX_ARR_LEN] = {&a, &b, &c, &d};

    printf("Array:");
    for (ptr2 = &p_arr[0]; *ptr2; ptr2++)
        printf(" %d", **ptr2);
    printf("\n");

    return 0;
}