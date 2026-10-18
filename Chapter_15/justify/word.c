#include <stdio.h>
#include "word.h"

int read_char(void) //word.c-only function
{
    int ch = getchar();

    if(ch == '\n' || ch == '\t') //checking if character read is a \n or \t
        return ' '; //if yes ' ' is returned
    return ch;  //if not ch is returned
}

void read_word(char *word, int len)
{
    int ch, pos = 0;

    while((ch = read_char()) == ' ')
        ; //skips all characters that include \n or \t
    while(ch != ' ' && ch != EOF){ //processes ch if ch != ' ' or EOF
        if(pos < len) //only reading characters of the input word until the specified length limit
            word[pos++] = ch; //post-fix increment moves pointer to next element spot of word after ch is input
        ch = read_char(); //next character of the word is read
    }
    word[pos] = '\0'; //at the end of the word we add a null char to indicate the end of the word string(strings need null char)
}
