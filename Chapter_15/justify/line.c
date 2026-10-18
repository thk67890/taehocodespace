#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;

void clear_line(void) //clearing line buffer
{
    line[0] = '\0'; //add null char at first element to signal that the string is blank
    line_len = 0; //reseting line_len var. that keeps track of current line length to 0
    num_words = 0; //reseting num_words var. that keeps track of current word # to 0
}

void add_word(const char *word)
{
    if(num_words > 0) { //if not the start of a new line
        line[line_len] = ' '; //add space before inputing the new word(originally the location of null char)
        line[line_len + 1] = '\0'; //restore the null char at the end of the string (preparing current line for strcat)
        line_len++; //move the pointer to the element that stores the first letter of the new word
    }

    strcat(line,word); //string concatenate the input word to current line string starting from the null char of the current line string
    line_len += strlen(word); // calculate and update line_len var. to track current line lenghth after including the new word
    num_words++; //increase num_words to update current # of words in the line
}

int space_remaining(void) //calculates the excess number of characters that the current line buffer can hold
{
    return MAX_LINE_LEN - line_len; //60chars - current line length
}

void write_line(void) //formating / justifying line
{
    int extra_spaces, spaces_to_insert, i, j;

    extra_spaces = MAX_LINE_LEN - line_len; //same as space_remaining
    for(i = 0; i < line_len; i++){ //locates ' ' within the line and equally distributes extra ' ' to format the line so that each line
        if(line[i] != ' ')         //has approximately the same lengths(60 chars)
            putchar(line[i]); //if line[i] is not a ' ' just print
        else {
            spaces_to_insert = extra_spaces / (num_words - 1); //calculating the equal number of extra ' ' for every incidence of ' ' in line
            for(j = 1; j <= spaces_to_insert + 1; j++) //adding equal number of extra ' ' to everu ' ' in line
                putchar(' ');
            extra_spaces -= spaces_to_insert; //updating remaining extra space after extra spaces have been inserted at some points of line
            num_words--; //updating number of words left that need to be written
        }
    }
    putchar('\n'); //ending line with a new-line char
}

void flush_line(void)
{
    if(line_len > 0)
        puts(line); //writing line w/o formatting / justifying
}