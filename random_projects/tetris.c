#include <ncurses.h>
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10


void init_board(int board[BOARD_HEIGHT][BOARD_WIDTH]);
void draw_board(int board[BOARD_HEIGHT][BOARD_WIDTH]);


enum PieceType { I_PIECE, O_PIECE, T_PIECE, S_PIECE, Z_PIECE, J_PIECE, L_PIECE};

struct Tetromino{
    int pos_row;
    int pos_col;
    enum PieceType type;
};

const int SHAPES[7][4][4][4] = {
                            {
                                //I
                                {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
                                {{0,0,1,0},{0,0,1,0},{0,0,1,0},{0,0,1,0}},
                                {{0,0,0,0},{0,0,0,0},{1,1,1,1},{0,0,0,0}},
                                {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}}
                            },
                                //O
                            {
                                {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}}
                            },
                                //T
                            {
                                {{0,0,0,0},{0,1,0,0},{1,1,1,0},{0,0,0,0}},
                                {{0,1,0,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,1},{0,0,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,0,1,0}}
                            },
                                //S
                            {
                                {{0,0,0,0},{0,1,1,0},{1,1,0,0},{0,0,0,0}},
                                {{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,0,1,1},{0,1,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}}
                            },    
                                //Z
                            {
                                {{0,0,0,0},{1,1,0,0},{0,1,1,0},{0,0,0,0}},
                                {{0,0,1,0},{0,1,1,0},{0,1,0,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,0},{0,0,1,1},{0,0,0,0}},
                                {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,1,0,0}}
                            
                            },
                                //J
                            {
                                {{0,0,0,0},{1,0,0,0},{1,1,1,0},{0,0,0,0}},
                                {{0,1,1,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,1},{0,0,0,1},{0,0,0,0}},
                                {{0,0,0,0},{0,0,1,0},{0,0,1,0},{0,1,1,0}}
                            },
                                //L
                            {
                                {{0,0,0,0},{0,0,1,0},{1,1,1,0},{0,0,0,0}},
                                {{0,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,1},{0,1,0,0},{0,0,0,0}},
                                {{0,0,0,0},{0,1,1,0},{0,0,1,0},{0,0,1,0}}
                            },                      
                        };


int main()
{
    int board[BOARD_HEIGHT][BOARD_WIDTH];

    initscr();
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

void draw_board(int board[BOARD_HEIGHT][BOARD_WIDTH]){ //draw board! move to tetris.c
    for(int i = 1; i <= BOARD_WIDTH; i++){
        mvprintw(0,i,"-");
        mvprintw(BOARD_HEIGHT+1,i,"-");
    }
    mvprintw(0,0,"+");
    mvprintw(0,BOARD_WIDTH+1,"+");
    
    for(int j = 1; j <= BOARD_HEIGHT; j++){
            mvprintw(j,0,"|");
            mvprintw(j,BOARD_WIDTH+1,"|");
    }
    mvprintw(BOARD_HEIGHT+1,0,"+");
    mvprintw(BOARD_HEIGHT+1,BOARD_WIDTH+1,"+");

    //Processing Board to print " " and "#"
    for(int i = 0; i < BOARD_HEIGHT; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            if(board[i][j] == 0) mvprintw(i+1,j+1," ");
            else mvprintw(i+1,j+1,"#");
        }
    } 

    refresh();

}
