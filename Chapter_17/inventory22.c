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
        printf("Enter an Action Code: ");
        scanf(" %c", &code);
        while(getchar() != '\n')
            ;
        switch(code){
            case 'i':  insert();
                       break;
            case 's':  search();
                       break;
            case 'u':  update();
                       break;
            case 'p':  print();
                       break;
            case 'q':  return 0;
            default :  printf("Wrong Code!\n");
        }
        printf("\n");
    }
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
    struct part *cur, *prev;

    struct part *new_node = malloc(sizeof(struct part));

    printf("Enter part number: ");
    scanf("%d",&new_node->number);

    for(prev = NULL, cur = inventory; cur != NULL && new_node->number < cur->number; cur = cur->next){
        ;
    }
    
    
    if(cur != NULL && cur->number == new_node->number){
        printf("Node alread exists!");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name,NAME_LEN);
    printf("Enter number on hand: ");
    scanf("%d",&new_node->on_hand);


    new_node->next = cur;
    if(prev == NULL) // adding new_node as the first element of the list
        inventory = new_node;
    else
        prev->next = new_node;


    
}

/*
search: prompts the user to enter a part hnumber, then looks up the part in the database. If the part exists, prints the name and 
quantity on hand; if not, prints an error message.
*/

void search(void){
    struct part *part;
    int number;
    printf("Enter a part number to Search: ");
    scanf("%d",&number);

    if(find_part(number) != NULL){
        part = find_part(number);
        printf("Name of Part: %s\n",part->name);
        printf("Quantity on hand: %d\n",part->on_hand);
    }

    else
        printf("Part does not Exist!");

}

/*
update: prompts the user to enter a part number. prints and error message if the part doesn't exists; otherwise, prompts the user to 
enter change in quantity on had and updates the database.
*/

void update(void){
    struct part *part;
    int number;
    int quantity;

    printf("Enter a part number to Update: ");
    scanf("%d",&number);

    if(find_part(number) != NULL){
        part = find_part(number);
        printf("Enter quantity to modify: ");
        scanf("%d", &quantity);
        part->on_hand += quantity;
    }

    else
        printf("Part does not exist!");

}

/*
print:prints a listing of all parts in the database, showing the part number, part name, and quantity on hand. Part numbers will appear
in ascending order.
*/

void print(void){
    struct part *ptr = inventory;

    printf("Part Number      Part Name        Quantity on Hand\n");
    for(; ptr != NULL; ptr = ptr->next){
        printf("%7d           %-26s%5d\n", ptr->number, ptr->name, ptr->on_hand);
    }
}

