//remind.c

#include <stdio.h>
#include <string.h>

#define MSG_LEN         4
#define DAY_LEN         2
#define MAX_REMINDERS   4

char reminders[MAX_REMINDERS][DAY_LEN + MSG_LEN + 1];

void read_day(char day_str[]);
void read_msg(char msg[]);
void ins_reminder(char day_str[], char msg[], int num_reminders);

int main(void) 
{
    char day_str[DAY_LEN+1], msg[MSG_LEN+1];
    
    printf("Enter day and reminder: ");
    read_day(day_str);
    read_msg(msg);

    //TODO comment out tests
    //test day_str[]
    printf("TEST: day_str = %s\n", day_str);
    //test msg[]
    printf("TEST: msg = %s\n", msg);

    // //test strcmp()
    // char a[] = "25", b[] = "5 dfgwdgdrsgs";
    // printf("a < b ? : %d\n", strcmp(b, a) > 0);


    return 0;
}

void read_day(char day_str[])
{
    int day;
    scanf("%2d", &day);
    sprintf(day_str, "%2d", day);
}

void read_msg(char msg[])
{
    int i;
    char ch;

    for (i = 0; ((ch = getchar()) != '\n') && (i <= MSG_LEN); i++) {
        msg[i] = ch;
    }
    msg[i] = '\0';
}

//ins_reminder(): insert reminder in ascending order (by day #)
void ins_reminder(char day_str[], char msg[], int num_reminders)
{
    int i, j;
    for (i = 0; (i < num_reminders) && (strcmp(day_str, reminders[i]) <= 0); i++)
        ;
    printf("i = %d\n", i);

}