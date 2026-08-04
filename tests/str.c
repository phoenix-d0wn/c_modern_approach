//str.c

#include <string.h>
#include <stdio.h>

#define STR_LEN 6

int main(void)
{
    char str2[STR_LEN+1] = "123456";

    strcpy(str2, "abcd");

    printf("%s\n", str2);
    printf("%d\n", (int) sizeof(str2));

    return 0;
}