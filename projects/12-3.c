//12-3.c

#include <stdio.h>

#define STR_MAX_LEN 199

int main(void)
{
    char msg[STR_MAX_LEN];
    char c;
    short i;

    //read message
    printf("Enter a message: ");
    for (i=0; (*(msg+i)=getchar()) != '\n'; i++) 
        ;

    //display reversed message
    printf("Reversal is: ");
    for (i--; i >= 0; i--)
        putchar(*(msg+i));

    return 0;
}