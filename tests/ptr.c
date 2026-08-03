//ptr.c

#include <stdio.h>



int main(void)
{
    char *str_ptr = "hello, world!\n";
    char str[]    = "hello, world!\n";

    putchar(str_ptr[15]);
    putchar(str_ptr[15]);

    // *str_ptr = '!';
    str[0]   = '!';

    int i_arr[] = {0,1,2,3,4,5};
    int *i_ptr  = {0};

    char n_ch = '1';
    int n_i   = 1;

    printf("%d", '0');

    // for (int i=0; i<2; i++) 
    //     printf("%d", *(i_ptr + i));

    return 0;
}