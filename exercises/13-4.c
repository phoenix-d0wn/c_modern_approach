//13-4.c

#include <stdio.h>

#define MAX_LINE    8

void read_line(char line[]);

int main(void)
{
    char line[MAX_LINE+1];

    read_line(line);
    printf("%s", line);

    return 0;
}

// (a) Have it skip white space before beginning to
//      input characters
// void read_line(char line[])
// {
//     char c;

//     while (c = getchar()) {
//         if (c != ' ' && c != '\t') {
//             line[0] = c;
//             break;
//         }
//     }

//     int i = 1;
//     for (; ((c = getchar()) != '\n') && (i < MAX_LINE); ) {
//         line[i++] = c;
//         printf("i = %d\n", i);  //test
//     }
//     line[i] = '\0';
// }

// (b) Have it stop reading at first white-space character
// void read_line(char line[])
// {
//     scanf("%s", line);
//     line[MAX_LINE] = '\0';
// }

// (c) Have it stop at the first newline character, then store
//      the newline '\n' in the string
void read_line(char line[]) 
{
    char c;

    int i = 0;
    for (; i < MAX_LINE; ) {
        c = getchar();
        line[i++] = c;

        if (c == '\n') {
            line[i++] = '\n';
            break;
        }
    }

    line[i] = '\0';
}