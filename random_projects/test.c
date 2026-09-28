#include <ncurses.h>
#define BOARD_HEIGHT 40
#define BOARD_WIDTH 80

void init_board(int board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int *p;
    int i;
    for(p = &board[0][0]; p <= &board[BOARD_HEIGHT-1][BOARD_WIDTH-1];p++){
        *p = 0;
        i++;
        printw(" %d ", *p);
        if(i % 40 == 0) {
            printw("\n");
        }
    }
}

void draw_board(int row, int col){ //draw board! move to tetris.c
    for(int i = 1; i < col-1; i++){
        mvprintw(0,i,"-");
        mvprintw(row-1,i,"-");
    }
    mvprintw(0,0,"+");
    mvprintw(0,col-1,"+");
    
    for(int j = 1; j < row-1; j++){
            mvprintw(j,0,"|");
            mvprintw(j,col-1,"|");
    }
    mvprintw(row-1,0,"+");
    mvprintw(row-1,col-1,"+");

    refresh();

}

int main()
{

    int row,col;
    //int board[40][80];
    
    initscr();
    getmaxyx(stdscr,row,col);
    draw_board(row,col);

    //init_board(board);

    mvprintw(10,10,"The max dimensions of the current terminal is: %d rows %d columns",row,col);

    refresh();
    getch();
    endwin();

}