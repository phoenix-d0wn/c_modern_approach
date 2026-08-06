//compare_str.h

#ifndef COMPARE_STR_H
#define COMPARE_STR_H

#include <stdbool.h>
#include <stdio.h>

/*******************************************************
*   compare_str:                                       *
*   1. take str1 and str2                              *
*   2. compare the two strings (ignores case)          *
*   3. return true if identical or false if otherwise  *
********************************************************/
bool compare_str(char str1[], char str2[])
{
    char *p_str1, *p_str2;

    for (p_str1 = str1, p_str2 = str2;
        *p_str1 != '\0' || *p_str2 != '\0';
        p_str1++, p_str2++) {

        //test
        // printf("ch1: %c\n", *p_str1);
        // printf("ch2: %c\n", *p_str2);
        // printf("\n");

        if (*p_str1 >= 97 && *p_str1 <= 122
            && *p_str2 >= 97 && *p_str2 <= 122) {

            if (*p_str1 != *p_str2)
                return false;
        } else if (*p_str1 >= 97 && *p_str1 <= 122) {

            if (*p_str1 - 32 != *p_str2)
                return false;
        } else if (*p_str2 >= 97 && *p_str2 <= 122) {

            if (*p_str1 != *p_str2 - 32)
                return false;
        } else {

            if (*p_str1 != *p_str2)
                return false;
        }
    }

    return true;
}

#endif