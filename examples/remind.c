//remind.c

#include <stdio.h>
#include <string.h>

#define MSG_LEN         60
#define DAY_LEN         2
#define MAX_REMINDERS   50

char reminders[MAX_REMINDERS][DAY_LEN + MSG_LEN + 1];
int num_reminders;

void read_day(char day_str[]);
void read_msg(char msg[]);
void ins_reminder(char day_str[], char msg[]);
void print_reminders(void);

int main(void) 
{
    char day_str[DAY_LEN+1], msg[MSG_LEN+1];
    int day;
    num_reminders = 0;
    


    // //TODO comment out tests
    // //test day_str[]
    // printf("TEST: day_str = %s\n", day_str);
    // //test msg[]
    // printf("TEST: msg = %s\n", msg);

    // //test strcmp()
    // char a[] = "25", b[] = "5 dfgwdgdrsgs";
    // printf("a < b ? : %d\n", strcmp(b, a) > 0);

    // //test ins_reminder()
    // ins_reminder(day_str, msg);

    for (;;) {

        if (num_reminders >= MAX_REMINDERS) {
            printf("--Max reminders reached!--\n");
            break;
        }

        printf("Enter day and reminder: ");

        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);

        read_msg(msg);
        ins_reminder(day_str, msg);

        num_reminders++;
    }
    print_reminders();

    return 0;
}

//TODO mb del later
void read_day(char day_str[])
{
    int day;

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
void ins_reminder(char day_str[], char msg[])
{
    int i, j;

    //find where in reminders[] to insert new reminder
    for (i = 0; (i < num_reminders) && (strcmp(day_str, reminders[i]) >= 0); i++)
        ;
    // printf("i = %d\n", i);  //test

    //shift all reminders to the right of new reminder by 1 position
    for (j = num_reminders; j > i; j--)
        strcpy(reminders[j], reminders[j-1]);

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg);

}

void print_reminders(void) {
    int i;

    printf("Day Reminder\n");
    for (i = 0; i < num_reminders; i++)
        printf(" %s\n", reminders[i]);
}