//10-3.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5
#define RANK_SUIT 2

//global variables
int hand[NUM_CARDS][RANK_SUIT];
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
    int card, i, rank, suit;
    char rank_ch, suit_ch, ch;
    bool bad_card, dupe_card;

    //TODO delete later
    // //initialize all elem in num_in_rank[] to 0 and card_exists[][] to false
    // for (rank=0; rank<NUM_RANKS; rank++) {
    //     num_in_rank[rank] = 0;
    //     for (suit=0; suit<NUM_SUITS; suit++) {
    //         card_exists[rank][suit] = false;
    //     }
    // }

    // //initialize all elem in num_in_suit[] to 0
    // for (suit=0; suit<NUM_SUITS; suit++) 
    //     num_in_suit[suit] = 0;

    //initialize all elems in hand[][]
    for (card=0; card<NUM_CARDS; card++) {
        for (i=0; i<RANK_SUIT; i++)
            hand[card][i] = 0;
    }

    int cards_read = 0;
    while (cards_read < NUM_CARDS) {
        bad_card = dupe_card = false;

        printf("Enter a card: ");
        rank_ch = getchar();
        suit_ch = getchar();

        switch (rank_ch) {

            case '0':           exit(EXIT_SUCCESS);
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

        switch (suit_ch) {

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
        
        //check for duplicate card
        for (card=0; card<cards_read; card++) {
            if (hand[card][0]==rank && hand[card][1]==suit) 
                dupe_card = true;
        }

        if (bad_card)
            printf("Card bad. Ignored\n");
        else if (dupe_card)
            printf("Card duplicate. Ignored\n");
        else {
            hand[cards_read][0]     = rank;
            hand[cards_read++][1]   = suit;
            // cards_read++;
        }
    }

    //for debug
    printf("Hand:\n");
    for (card=0; card<NUM_CARDS; card++) {
        printf("[%d]: %d%d\n", card, hand[card][0], hand[card][1]);
    }

}

//analyze_hand: goes thru num_in_rank[] and num_in_suit[] and determine the hand
void analyze_hand(void) 
{
    int card, rank_recurr, max_recurr;
    bool pair_switch;
    int rank, suit;

    straight = flush = true;
    four = three = false;
    pairs = 0;  //can be 0-2

    //check for flush
    suit = hand[0][1];
    for (card=1; card<NUM_CARDS; card++) {

        if (hand[card][1] != suit) 
            flush = false;  break;
    }

    //check for straight
    rank = hand[0][0];
    for (card=1; card<NUM_CARDS; card++) {

        if (hand[card][0] != rank)
            straight = false;  break;
    }

    //check for pairs, threes, and fours
    max_recurr = 1;
    for (int i=0; i<NUM_CARDS-1; i++) {

        pair_switch = 0;
        rank_recurr = 1;
        for (int j=i+1; j<NUM_CARDS; j++) {
            if (hand[i][0] == hand[j][0])
                rank_recurr++;
        }

        if (rank_recurr > max_recurr)
            max_recurr = rank_recurr;
        if (rank_recurr == 2)
            pairs++;
    }

    if      (max_recurr == 4)   four    = true;
    else if (max_recurr == 3)   three   = true;
    else if (max_recurr == 2)   pairs   = true;     //TODO update checking for pairs

    //test analyze_hand
    printf("Straight?:\t%b\n", straight);
    printf("Flush?:\t\t%b\n", flush);
    printf("Four?:\t\t%b\n", four);
    printf("Three?:\t\t%b\n", three);
    printf("Pairs:\t\t%d\n", pairs);
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