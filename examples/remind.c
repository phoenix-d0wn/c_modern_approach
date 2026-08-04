//remind.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSG_LEN     60
#define DAY_LEN     2
#define MAX_REMINDS 50

char remind[MAX_REMINDS][DAY_LEN + MSG_LEN + 1];

int read_msg(char msg_str[]);

int main(void)
{
    int num_reminds = 0;
    int day;
    char day_str[DAY_LEN+1], msg_str[MSG_LEN + 1];
    int i, j;



    for (;;) {
        
        if (num_reminds >= MAX_REMINDS) {
            printf("--Max reminders reached!--");   
            break;
        }

        // printf("****TEST******\n");
        printf("Enter day and reminder: ");
        scanf("%d", &day);

        if (day == 0)   break;      //stop entering reminders

        sprintf(day_str, "%2d", day);
        read_msg(msg_str);

        for (i = 0; (strcmp(day_str, remind[i]) > 0) && (i < num_reminds); i++)
            // printf("i = %d\n", i);
        for (j = num_reminds; j > i; j--) {
            strcpy(remind[j], remind[j - 1]);
            // printf("j = %d\n", j);
        }

        strcpy(remind[i], day_str);
        strcat(remind[i], msg_str);

        num_reminds++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_reminds; i++)
        printf("%s\n", remind[i]);



    return 0;
}

int read_msg(char msg_str[])
{
    char ch;
    int i;

    for (i = 0; ((ch = getchar()) != '\n') && (i < MSG_LEN); i++) {

        msg_str[i] = ch;
    }
    msg_str[i] = '\0';
    
    return i;
}