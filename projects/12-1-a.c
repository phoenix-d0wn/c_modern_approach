//12-1.c

#include <stdio.h>

#define STR_MAX_LEN 199

int main(void)
{
    char msg[STR_MAX_LEN];
    short i;
    char c;

    //read message
    printf("Enter a message: ");
    i = 0;
    while ((c = getchar()) != '\n')
        msg[i++] = c;

    //display reversed message
    printf("Reversal is: ");
    for (; i >= 0; i--)
        printf("%c", msg[i]);

    return 0;
}