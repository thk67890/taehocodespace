#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs;

void read_cards(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    for(;;) { //Infinite loop
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

    //Initializing deck before card is read
    for(rank = 0; rank < NUM_RANKS; rank++){
        num_in_rank[rank] = 0; //initializing num_in_rank array
        for(suit = 0; suit < NUM_SUITS; suit++) {
            num_in_suit[suit] = 0; //initializing num_in_suit array
            card_exists[rank][suit] = false; //initializing existing card tracker array
        }
    }
    //both suits and ranks arr are give default value of 0.
    //When a card of N suit and N rank is given, element at 
    //N position of suit and rank arr is incremented 
    //to 1 to indicate that such card has been selected


    //Starting Read Card procedure after intialization
    while(cards_read < NUM_CARDS){
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar(); //First character entered after prompt above is saves as rank_ch
        switch(rank_ch){ //input char of rank_ch sorted through switch, case
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7':rank = 5; break;
            case '8':rank = 6; break;
            case '9':rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default: bad_card = true;
        }

        suit_ch = getchar();//Second char entered after prompt saved as suit_ch
        switch(suit_ch) {//input char of suit_ch sorted through switch, case
            case 'c': case 'C' : suit = 0; break;
            case 'd': case 'D' : suit = 1; break;
            case 'h': case 'H' : suit = 2; break;
            case 's': case 'S' : suit = 3; break;
            default: bad_card = true;
        }

        while((ch = getchar()) != '\n'){ //checking for unnecessary new-line char input
            if (ch != ' ') bad_card = true;
        }
        if(bad_card){ //bad card response
            printf("Bad card; ignored.\n");
        }
        else if(card_exists[rank][suit]){ //checking if input is a duplicate card
            printf("Duplicate card; ignored.\n");
        }
        else {
            num_in_rank[rank]++; //incrementing respective element in num_in_rank arr
            num_in_suit[suit]++; //incrementing respective element in num_in_suit arr
            card_exists[rank][suit] = true; //marking respective card as existing to prevent duplicate cards
            cards_read++; //incrementing num of cards read(N of 5)
        }
    }

}

void analyze_hand(void)
{
    int num_consec = 0;
    int rank, suit;

    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;

    for(suit = 0; suit < NUM_SUITS; suit++){
        if(num_in_suit[suit] == NUM_CARDS){ //Five Same Suit Cards --> Flush Detected
            flush = true;
        }
    }

    rank = 0;

    //Initialization for detecting number of consecutive rank cards
    while(num_in_rank[rank] == 0) rank++; //finding lowest number of consecutive rank
    for(; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++){ //counting how many suits are lined up consecutively starting from intially detected rank above
        num_consec++;
    }
    if(num_consec == NUM_CARDS){
        straight = true; //If cards are all in line consecutively --> Straight detected
        return;
    }

    for(rank = 0; rank < NUM_RANKS; rank++){ //Counting number of cards with the same rank (N of a kind detection)
        if(num_in_rank[rank] == 4) four = true;
        if(num_in_rank[rank] == 3) three = true;
        if(num_in_rank[rank] == 2) pairs++;
    }
}

void print_result(void) //printing results
{
    if(straight && flush) printf("Straight flush");
    else if(four)         printf("Four of a Kind");
    else if(three &&
            pairs == 1)   printf("Full house");
    else if(flush)        printf("Flush");
    else if(straight)     printf("Straight");
    else if(three)        printf("Three of a kind");
    else if(pairs == 2)     printf("Two Pair");
    else if(pairs == 1)     printf("Pair");
    else                    printf("High Card");

    printf("\n");
}