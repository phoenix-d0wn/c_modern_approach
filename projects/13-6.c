//13-6.c

#include "../headers/compare_str.h"
#include <stdio.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    char *planets[NUM_PLANETS] = {
        [0] = "Mercury",
        [1] = "Venus",
        [2] = "Earth",
        [3] = "Mars",
        [4] = "Jupiter",
        [5] = "Saturn",
        [6] = "Uranus",
        [7] = "Neptune",
        [8] = "Plutno"
    };

    char **p_argv;
    int i_planet;
    bool planet_found;
    for (p_argv = &argv[1]; *p_argv != NULL; p_argv++) {
        planet_found = false;

        for (i_planet = 0; i_planet < NUM_PLANETS; i_planet++) {
            if (compare_str(planets[i_planet], *p_argv)) {
                planet_found = true;
                break;
            }
        }

        if (!planet_found)
            printf("%s is not a planet\n", *p_argv);
        else
            printf("%s is planet #%d\n", *p_argv, i_planet+1);
    }

    return 0;
}

