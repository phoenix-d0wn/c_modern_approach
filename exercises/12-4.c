//12-4.c

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
// int top = 0;
int *top = &contents[0];

int main(void) 
{
    
}

void make_empty(void) { top = &contents[0]; }

bool is_empty(void) { return top == &contents[0]; }

bool is_full(void) { return top == &contents[STACK_SIZE]; }

void push(int i)
{
    if (is_full())
        // stack_overflow();
        ;
    else
        *(top++) = i;
}

int pop(void) 
{
    if (is_empty())
        // stack_underflow();
        ;
    else
        return *(--top);
}