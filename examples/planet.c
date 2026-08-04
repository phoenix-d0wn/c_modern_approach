//planet.c

#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 8

int main(int argc, char *argv[])
{
    char *planets[] = {
        [0] =   "Mercury",
        [1] =   "Venus",
        [2] =   "Earth",
        [3] =   "Mars",
        [4] =   "Jupiter",
        [5] =   "Saturn",
        [6] =   "Uranus",
        [7] =   "Neptune"
    };

    int i, j;

    for (i = 1; i < argc; i++) {
        
        for (j = 0; j < NUM_PLANETS; j++) {

            if (strcmp(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }

        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }

    return 0;
}