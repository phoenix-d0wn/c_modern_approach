//13-1.c

#include <stdio.h>
#include <string.h>

#define MIN_WORD_LEN    1
#define MAX_WORD_LEN    20

//global variables
char smallest_word[MAX_WORD_LEN + 1];
char largest_word[MAX_WORD_LEN + 1];

int main(void)
{
    char word[MAX_WORD_LEN + 1];

    // //TEST
    // printf("Smallest word: %s\n", smallest_word);

    // //test word[]
    // printf("Enter word: ");
    // scanf("%s", &word);
    // printf("Word: %s\n", word);

    // //test strcmp()
    // printf("strcmp(word, smallest_word): %d\n",
    //     strcmp(word, smallest_word));

    // //test smallest_word[]
    // strcpy(smallest_word, word);
    // printf("Smallest word: %s\n", smallest_word);

    // //test strcmp()
    // printf("strcmp(word, smallest_word): %d\n",
    //     strcmp("a", smallest_word));

    for (;;) {

        printf("Enter word: ");
        scanf("%s", &word);

        //test
        // printf("\n");
        // printf("strcmp(word, smallest_word) = %d\n",
        //         strcmp(word, smallest_word));
        // printf("strcmp(word, largest_word) = %d\n",
        //         strcmp(word, largest_word));
        // printf("word: %s\n", word);
        // printf("smallest word: %s\n", smallest_word);
        // printf("largest word: %s\n", largest_word);
        // printf("\n");

        if (strcmp(word, smallest_word) < 0 || strlen(smallest_word) == 0)
            strcpy(smallest_word, word);
        if (strcmp(word, largest_word) > 0 || strlen(largest_word) == 0)
            strcpy(largest_word, word);

        if (strlen(word) == 4)
            break;
    }

    printf("\n");
    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}