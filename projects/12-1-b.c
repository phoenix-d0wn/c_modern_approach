//12-1-b.c

#include <stdio.h>

#define STR_MAX_LEN 199

int main(void)
{
    char msg[STR_MAX_LEN];
    char *i;
    char c;

    //read message
    printf("Enter a message: ");
    i = msg;
    while ((c = getchar()) != '\n')
        *(i++) = c;

    //display reversed message
    printf("Reversal is: ");
    for (; i >= msg; i--)
        printf("%c", *i);

    return 0;
}