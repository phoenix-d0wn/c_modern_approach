//12-13.c

# include <stdio.h>

#define N 10

int main(void)
{
    double ident[N][N];
    double *ptr;

    //create an identity matrix
    for (ptr=&ident[0][0]; ptr<=&ident[N-1][N-1]; ptr++) {
        if ((ptr - &ident[0][0]) % 11 == 0)
            *ptr = 1.0;
        else
            *ptr = 0.0;
    }

    //print the identity matrix
    printf("Identity Matrix = \n");
    for (ptr=&ident[0][0]; ptr<=&ident[N-1][N-1]; ptr++) {
        if ((ptr - &ident[0][0] + 1) % 10 == 0)
            printf(" %d\n", (int) *ptr);
        else
            printf(" %d", (int) *ptr);
    } 
}