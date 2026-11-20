#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#define NAME_LEN 25

struct part{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/*
main: prompts the user to enter an operation code, then calls a function to perform the requested action. Repeats until the user enters
the command 'q'. Prints an error message if the user enter an illegal code
*/
int main(void)
{
    char code;
    for(;;){
        printf("Enter an action code: ");
        scanf(" %c",&code);
        while(getchar() != '\n');
            ;

        switch(code){
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'q': return 0;
            default : printf("Wrong Code!\n");
        }
        printf("\n");
    }

    return 0;
    
}

/*
find_part: looksp up a part number in the inventory list. Returns a pointer to the node containing the part number; if the part number
is not found, returns NULL
*/

struct part *find_part(int number){
    struct part *p;
    for(p = inventory; p != NULL && p->number != number; p = p->next)
        ;
    return p;

}

/*
insert: prompts the user for information about a new part and then inserts the part into the inventory list; the list remains sorted by 
part number. Prints an error message and returns prematurely if the part already exists or space could not be allocated for the part
*/

void insert(void){
    struct part *new_node, *prev, *curr;

    new_node = malloc(sizeof(struct part));

    if(new_node == NULL){
        printf("NO MEMORY LEFT!");
        free(new_node);
        return;
    }

    printf("Enter a part number: ");
    scanf("%d",&new_node->number);

    
    for(prev = NULL, curr = inventory; curr != NULL && curr->number < new_node->number;
            prev = curr, curr = curr->next)
        ;
    if(curr != NULL && curr->number == new_node->number){
        printf("Part already exists!");
        free(new_node);
        return;
    }

    printf("Enter the name of the part: ");
    read_line(new_node->name,NAME_LEN);

    printf("Enter the quantity at hand: ");
    scanf("%d",&new_node->on_hand);
    
    new_node->next = curr;
    if(prev == NULL){
        inventory = new_node;
    }
    else{
        prev->next = new_node;
    }


}

/*
search: prompts the user to enter a part hnumber, then looks up the part in the database. If the part exists, prints the name and 
quantity on hand; if not, prints an error message.
*/

void search(void){
    int number;
    struct part *p;
    printf("Enter a part number to search: ");
    scanf("%d", &number);
    p = find_part(number);

    if(p == NULL){
        printf("Part does not exists!\n");
    }
    else{
        printf("Part Name: %s\nQuantity on hand: %d\n",p->name,p->on_hand);
    }

}

/*
update: prompts the user to enter a part number. prints and error message if the part doesn't exists; otherwise, prompts the user to 
enter change in quantity on had and updates the database.
*/

void update(void){
    int number,change;
    struct part *p;
    printf("Enter a part number to update: ");
    scanf("%d", &number);
    p = find_part(number);

    if(p == NULL){
        printf("Part does not exist\n");
    }
    
    printf("Enter a quantity on hand to update: ");
    scanf("%d", &change);
    p->on_hand += change;
}

/*
print:prints a listing of all parts in the database, showing the part number, part name, and quantity on hand. Part numbers will appear
in ascending order.
*/

void print(void){
    struct part *p;

    printf("Part Number      Part Name        Quantity on Hand\n");
    for(p = inventory; p != NULL; p = p->next){
        printf("%7d           %-26s%5d\n", p->number, p->name, p->on_hand);
    }
}



