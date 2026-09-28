#include <ncurses.h>
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 15


void init_board(int board[BOARD_HEIGHT][BOARD_WIDTH]);
void draw_board(int board[BOARD_HEIGHT][BOARD_WIDTH]);



int main()
{
    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int row,col;
    /*
    initscr();
    printw("Hello World!");
    refresh();
    getch(); 
    */

    initscr();
    getmaxyx(stdscr,row,col);
    printw("max row %d col %d",row,col);

    init_board(board);
    draw_board(board);
    refresh();
    getch();
    endwin();
}

void init_board(int board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int *p;
    for(p = &board[0][0]; p <= &board[BOARD_HEIGHT-1][BOARD_WIDTH-1];p++){
        *p = 0;
    }
}

void draw_board(int board[BOARD_HEIGHT][BOARD_WIDTH])
{
    for(int i = 0; i < BOARD_HEIGHT; i++)
    {
        mvprintw(i,0,"|");
        mvprintw(i,BOARD_WIDTH-1,"|");
    }

    for(int j = 0; j < BOARD_WIDTH; j++)
    {
        mvprintw(0,j,"-");
        mvprintw(BOARD_HEIGHT-1,j,"-");
    }
    
    for(int y = 0; y < BOARD_HEIGHT; y++){
        for(int x = 0; x < BOARD_WIDTH; x++){
            if(board[y][x] == ' '){
                mvprintw(y,x,"1");
            }
            else mvprintw(y,x,"#");
        }
    }

    refresh();

}