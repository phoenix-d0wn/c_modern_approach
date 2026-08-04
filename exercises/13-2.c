//13-2.c

#include <stdio.h>

int main(void)
{
    //QUESTION
    //Suppose p is declared as follows:
    char *p = "abc";

    //Which of the following functions are legal? Show the output produced by each legal call, and explain why the others are illegal.
    // putchar(p);  // (a)  ILLEGAL -- p is not a char
    putchar(*p);    // (b)
    puts(p);        // (c) 
    // puts(*p);    // (d)  ILLEGAL -- *p is not a pointer

    return 0;
}