#include <ncurses.h>
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10


enum PieceType { I_PIECE, O_PIECE, T_PIECE, S_PIECE, Z_PIECE, J_PIECE, L_PIECE};

struct Tetromino{
    double pos_row;
    double pos_col;
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


void init_board(int board[BOARD_HEIGHT][BOARD_WIDTH]);
void draw_board(int board[BOARD_HEIGHT][BOARD_WIDTH]);
void draw_piece(struct Tetromino piece);
bool can_move(struct Tetromino,int board[BOARD_HEIGHT][BOARD_WIDTH],int row_offset, int col_offset);


int main()
{
    int ch;
    double GRAVITY = 0.01;

    struct Tetromino piece = {0,0, I_PIECE};

    int board[BOARD_HEIGHT][BOARD_WIDTH];
    int row_offset = 1;
    int col_offset = 1;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(20); //non-blocking doesn't wait for user input to start

    init_board(board);
    draw_board(board);
    draw_piece(piece);
    refresh();

    while((ch = getch()) != 'q'){
        piece.pos_row += GRAVITY;
        if(ch == KEY_LEFT){
            piece.pos_col -= 1;
        } else if(ch == KEY_RIGHT){
            piece.pos_col +=1;
        }
        if(can_move(piece,board,1,1)) {
            clear();
            draw_board(board);
            draw_piece(piece);
            mvprintw(10,20, "current row: %f current col: %f",piece.pos_row,piece.pos_col);
            refresh();
        }
        
    }

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

void draw_piece(struct Tetromino piece){
    int r, c;
    int board_row, board_col;
    //boarder condiseration

    for(r = 0; r < 4; r++){
        for(c = 0; c < 4; c++){
            board_row = piece.pos_row + r;
            board_col = piece.pos_col + c;
            if(SHAPES[piece.type][0][r][c] == 1) mvprintw(board_row + 1,board_col + 1,"#");
            
        }
    }

    refresh();
}


bool can_move(struct Tetromino piece,int board[BOARD_HEIGHT][BOARD_WIDTH],int row_offset, int col_offset){
    int offset_board_row, offset_board_col, r,c,count;

    for(r = 0; r < 4; r++){
        count = 0;
        for(c = 0; c < 4; c++){
            offset_board_row = piece.pos_row + r + row_offset;
            offset_board_col = piece.pos_col + c + col_offset;
            if((SHAPES[piece.type][0][r][c] == 1) && (offset_board_row <= 10) && (offset_board_col <= 10) && (offset_board_col >= 1)) count++;
            //else if(board[][board_col] != 0) return false; //stop if spot is already filled
        }
    }
    if(count == 4) return true; //returns false if any of the unit blocks(every piece has 4 blocks) have a position that overwrites the boundaries
    //else return false;
    else return true;


}