//Modify the poker.c program of Section 10.5 by allowing "ace-low" straights (ace,two,three, four, five)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three, ace_straight;
bool ace;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    while(getchar() != 'q') {
        read_cards();
        analyze_hand();
        print_result();

    }
}

void read_cards(void)
{
    bool card_exists[NUM_RANKS][NUM_SUITS];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for(rank = 0; rank < NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for(suit = 0; suit < NUM_SUITS; suit++)
            card_exists[rank][suit] = false;
    }

    for(suit = 0; suit < NUM_CARDS; suit++) {
        num_in_suit[suit] = 0;
    }

    while(cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':exit(EXIT_SUCCESS);
            case '2':rank = 0; break;
            case '3':rank = 1; break;
            case '4':rank = 2; break;
            case '5':rank = 3; break;
            case '6':rank = 4; break;
            case '7':rank = 5; break;
            case '8':rank = 6; break;
            case '9':rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; ace = true; break;
            default: bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default: bad_card = true;
        }

        while((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;
        
        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists[rank][suit])
            printf("Duplicae card; ignored.\n");
        else {
            num_in_rank[rank]++; //Marking Rank of Collected Card by incrementing array element of that rank
            num_in_suit[suit]++; //Marking Suit of Collected Card by incrementing array element of that suit
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyze_hand(void)
{
    int num_consec = 0;
    int rank_temp,rank, suit;

    straight = false;
    flush = false;
    four = false;
    three = false;
    ace_straight = false;
    
    bool rank_check = false;
    
    pairs = 0;

    for(suit = 0; suit < NUM_SUITS; suit++){ //if all cards in the hand have the same suit --> FLUSH
        if(num_in_suit[suit] == NUM_CARDS){
            flush = true;
        }
    }

    rank = 0;
    
    while(num_in_rank[rank] == 0) rank++; //searching for the start of consecutive ranks in the hand

    if (rank == 0) rank_check = true;
    
    for(; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++){ //counting how many ranks are consecutive in the hand
        num_consec++;
    }
    if(rank_check == true && (num_consec == NUM_CARDS-1) && ace == true){
        //printf("Ace detected");
        ace_straight = true;
    }
    if(num_consec == NUM_CARDS) { //if the number of consecutive cards is equal to the total number of cards in the hand --> Straight
        straight = true;
        return;
    }

    for(rank = 0; rank < NUM_RANKS; rank++) {
        if(num_in_rank[rank] == 4) four = true; //4 cards of the same rank --> four of a kind
        if(num_in_rank[rank] == 3) three = true; //3 cards of the same rank --> three of a kind
        if(num_in_rank[rank] == 2) pairs++; //2 cards of the same rank --> one pair
    }
}

void print_result(void)
{
    if(straight && flush)   printf("Straight flush");
    else if(ace_straight)   printf("Ace Low");
    else if(four)           printf("Four of a Kind");
    else if(three &&
            pairs == 1)     printf("Full house");
    else if(flush)          printf("Flush");
    else if(straight)       printf("Straight");
    else if(three)          printf("Three of a kind");
    else if(pairs == 2)     printf("Pair");
    else if(pairs == 1)     printf("High card");

    printf("\n");
}