#include <ncurses.h>

int main()
{
    int ch;
    
    initscr();
    raw();
    
    printw("Type any character to see it in bold\n");
    ch = getch();

    printf("The pressed key is ");
    attron(A_BOLD);
    printw("%c",ch);
    attroff(A_BOLD);

    refresh();
    getch();
    endwin();

    return 0;

}