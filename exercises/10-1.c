//10-1.c

#include <stdio.h>

int a;

void f(int b) 
{ 
    int c; 
}

void g(void)
{
    int d;
    {
        int e;
    }
}

int main(void) 
{
    int f;   

    //QUESTION
    //For each of the following scopes, list all variable and parameter names visible in that scope
    // (a) The f function
    // (b) The g function
    // (c) The block in which e is declared
    // (d) The main function

    //ANSWER
    // (a) c        --INCORRECT: a, b c
    // (b) d, e     --INCORRECT: a, d
    // (c) d, e     --INCORRECT: a, d, e
    // (d) f        --INCORRECT: a, f
}