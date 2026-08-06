//13-4.c

#include <stdio.h>

int main(int argc, char *argv[])
{
    //technique A
    // for (int idx = argc - 1; idx > 0; idx--) {
    //     printf("%s ", argv[idx]);
    // }

    
    //technique B
    char **p;
    for (p = &argv[argc-1]; p != argv; p--)
        printf("%s ", *p);

    // printf("%d\n", argc);

    // p = &argv[argc - 1];
    // printf("%s ", *p);
    // p = &argv[argc - 2];
    // printf("%s ", *p);
    // p = &argv[argc - 3];
    // printf("%s ", *p);
    // p = &argv[argc - 4];
    // printf("%s ", *p);
    // // p = &argv[argc - 5];
    // // printf("%s ", *p);

    return 0;
}