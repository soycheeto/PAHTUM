#include <stdio.h>

//Function Declarations
#define SIZE 7

int playMove(char board[SIZE][SIZE], char player, int *x, int *y){
    int validMove=1;
    printf("Player %c move:\n", player);
    printf("Input x coordinate:\n");
    scanf("%d", x);
    printf("Input y coordinate:\n");
    scanf("%d", y);
    if(((*x)>=0 && (*x)<SIZE) &&((*y)>=0 &&(*y)<SIZE) &&board[*x][*y]==' '){
        board[*x][*y]= player;
        printBoard(board);
    }
    else{
        validMove = 0;
    }

    return validMove;

}

initializeBoard(char board[SIZE][SIZE]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            board[i][j] = ' ';
        }
    }
}

printBoard(char board[SIZE][SIZE]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}


scoreBoard(char board[SIZE][SIZE], int countX[SIZE], int countO[SIZE]);
printScores(char board[SIZE][SIZE]);
playGame(char board[SIZE][SIZE], char player1,char player2);

int main(void){
    char board[SIZE][SIZE];
    initializeBoard(board);
    char player1 = 'x';
    char player2 = 'o';
    return 0;
}
