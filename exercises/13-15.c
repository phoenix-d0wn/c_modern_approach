//13-15.c

#include <string.h>
#include <stdio.h>

int f(char *s, char *t);

int main(void)
{
    char a[] = "abcd", b[] = "babc";
    printf("a = \"abcd\", b = \"babc\"\n");
    printf("f returns: %d\n", f(a, b));

    strcpy(b, "bcd");
    printf("a = \"abcd\", b = \"bcd\"\n");
    printf("f returns: %d\n", f(a, b));

    //QUESTION
    //  let f be the following function
    //  (a) What is the value of f("abcd", "babc")?
    //  (b) What is the value of f("abcd", "bcd")?
    //  (c) In general, what value does f return when passed two
    //      strings s and t?

    //ANSWER
    //  (a) 3   --CORRECT
    //  (b) 0   --CORRECT
    //  (c) f returns the index in string s of the character
    //      absent from string t   
    //          -- CORRECT; more specifically, the index of the first
    //              char in s that is no also in t     

    return 0;
}

int f(char *s, char *t)
{
    char *p1, *p2;

    for (p1 = s; *p1; p1++) {

        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        
        if (*p2 == '\0')    break;
    }

    return p1 - s;
}