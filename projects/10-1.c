//10-1.c

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
char *top = contents;

/****************/
/* Prototypes   */
/****************/
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(const char *i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    char braces[STACK_SIZE];
    int i;
    char c, popped;

    printf("Enter parentheses and/or braces: ");
    for (; (c=getchar()) != '\n'; ) {
        if (c == '(' || c == '{')
            push(&c);

        else if (c == ')' || c == '}') {
            popped = pop();
            if ((c==')' && popped!='(') ||  (c=='}' && popped!='{')) {
                printf("Parentheses/braces are NOT nested properly");
                return 0;
            }
        }
    }
    
    if (is_empty())
        printf("Parentheses/braces are nested properly");
    else
        printf("Parentheses/braces are NOT nested properly");

    // printf("\n\n");
    // //test stack
    // for (; !is_empty(); ) {
    //     printf("%c", *(top--));
    // }

    return 0;
}   //end main

/***********************/
/* Function Definitions*/
/***********************/

void make_empty(void) { top = contents; }

bool is_empty(void) {return top == contents; }

bool is_full(void) { return top == contents + STACK_SIZE-1; }

void push(const char *i)
{
    if (is_full())  stack_overflow();
    else            *(++top) = *i;
}

char pop(void)
{
    if (is_empty()) {
        stack_underflow();
        return '\0';
    } else            
        return *(top--);
}

void stack_overflow(void) { printf("\nStack overflow!"); }

void stack_underflow(void) { printf("\nStack underflow!"); }