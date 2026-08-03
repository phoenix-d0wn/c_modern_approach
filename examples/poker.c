//poker.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

//global variables
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];

bool flush, straight, four, three;
int pairs;      //can be 0-2

//prototypes
void read_hand(void);
void analyze_hand(void);
void print_result(void);


//main: calls read_hand, analyze_hand, and print_result repeatedly
int main(void)
{

    for (;;){
        read_hand();
        analyze_hand();
        print_result();
    }

    return 0;
}

//read_hand: read 5 cards and store in num_in_rank[] (global), num_in_suit[] (global),
//  and card_exists[][]
void read_hand(void)
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    int rank, suit;
    char ch_rank, ch_suit, ch;
    bool bad_card;

    //initialize all elem in num_in_rank[] to 0 and card_exists[][] to false
    for (rank=0; rank<NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for (suit=0; suit<NUM_SUITS; suit++) {
            card_exists[rank][suit] = false;
        }
    }

    //initialize all elem in num_in_suit[] to 0
    for (suit=0; suit<NUM_SUITS; suit++) 
        num_in_suit[suit] = 0;

    int cards_read = 0;
    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");
        ch_rank = getchar();
        ch_suit = getchar();

        switch (ch_rank) {

            case '0': exit(EXIT_SUCCESS);
            case '2':           rank = 0;   break;
            case '3':           rank = 1;   break;
            case '4':           rank = 2;   break;
            case '5':           rank = 3;   break;
            case '6':           rank = 4;   break;
            case '7':           rank = 5;   break;
            case '8':           rank = 6;   break;
            case '9':           rank = 7;   break;
            case 't': case 'T': rank = 8;   break;
            case 'j': case 'J': rank = 9;   break;
            case 'q': case 'Q': rank = 10;  break;
            case 'k': case 'K': rank = 11;  break;
            case 'a': case 'A': rank = 12;  break;
            default :           bad_card = true;
        }

        switch (ch_suit) {

            case 'c': case 'C': suit = 0;   break;
            case 'd': case 'D': suit = 1;   break;
            case 'h': case 'H': suit = 2;   break;
            case 's': case 'S': suit = 3;   break;
            default:            bad_card = true;
        }

        //for debug
        // printf("Rank: %d; Suit: %d\n", rank, suit);

        while ((ch=getchar()) != '\n')
            if (ch != ' ')  bad_card = true;
        
        if (bad_card)
            printf("Card bad. Ignored\n");
        else if (card_exists[rank][suit])
            printf("Card duplicate. Ignored\n");
        else {
            card_exists[rank][suit] = true;
            num_in_rank[rank]++;    num_in_suit[suit]++;
            cards_read++;
        }
    }

    //for debug
    // printf("Num in Ranks:\n");
    // for (rank=0; rank<NUM_RANKS; rank++)
    //     printf("[%d]\t=\t%d\n", rank, num_in_rank[rank]);

    // printf("Num in Suits:\n");
    // for (suit=0; suit<NUM_SUITS; suit++)
    //     printf("[%d]\t=\t%d\n", suit, num_in_suit[suit]);

}

//analyze_hand: goes thru num_in_rank[] and num_in_suit[] and determine the hand
void analyze_hand(void) 
{
    int rank, suit;

    straight = flush = four = three = false;
    pairs = 0;  //can be 0-2

    //check for flush
    for (suit=0; suit<NUM_SUITS; suit++)
        if (num_in_suit[suit] == 5) flush = true;

    //check for straight
    int num_recurr = 0;
    for (rank = 0; num_in_rank[rank] == 0; rank++)
        ;
    for (; (num_recurr < NUM_CARDS) && (num_in_rank[rank] != 0); rank++)
        num_recurr++;
    if (num_recurr == 5)    straight = true;

    //check for pairs, threes, and fours
    for (rank = 0; rank < NUM_RANKS; rank++) {
        if      (num_in_rank[rank] == 2) pairs++;
        else if (num_in_rank[rank] == 3) three  = true;
        else if (num_in_rank[rank] == 4) four   = true;
    }

    //test analyze_hand
    // printf("Straight?:\t%b\n", straight);
    // printf("Flush?:\t%b\n", flush);
    // printf("Four?:\t%b\n", four);
    // printf("Three?:\t%b\n", three);
    // printf("Pairs:\t%d\n", pairs);
}

//print_result: print the kind of hand user has
void print_result(void)
{
    if (straight && flush)
        printf("Straight flush\n");
    else if (four)
        printf("Four-of-a-kind\n");
    else if (three && (pairs = 1))
        printf("Full house\n");
    else if (flush)
        printf("Flush\n");
    else if (straight)
        printf("Straight\n");
    else if (three)
        printf("Three\n");
    else if (pairs == 2)
        printf("Two pairs\n");
    else if (pairs == 1)
        printf("Pair\n");
    else
        printf("High card\n");
    printf("\n");
}