#include <string.h>
#include "word.h"
#include "line.h"

#define MAX_WORD_LEN 20

int main(void)
{
    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for(;;){
        read_word(word, MAX_WORD_LEN+1); //read word at max length first so that all words up to 20 chars are read
        word_len = strlen(word); //determine the actual length of the new word(!sizeof but strlen for this reason)
        if(word_len == 0) { //if input word is a blank, it indicates that we've come to the end of the quote file
            flush_line();   //thus push the current input without justifiction(flush_line()) and then end program by return 0
            return 0;
        }

        if(word_len > MAX_WORD_LEN) // if new word exceeds word length limit add astrisk at 20th char of new word
            word[MAX_WORD_LEN] = '*';
        if(word_len + 1 > space_remaining()) { //if new word exceeds current line buffer when added, push current line buffer content,
            write_line();                      //clear line, then add_word to new blank line buffer
            clear_line();
        }
        add_word(word);
    
    }
}