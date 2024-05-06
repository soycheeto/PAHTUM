#include <stdio.h>

/*
Function Declarations*/

#define SIZE 7
playMove(char board[SIZE][SIZE], char player, int *x, int *y);
initializeBoard(char board[SIZE][SIZE]);

printBoard(char board[SIZE][SIZE]){
    int i, j;
    for(i=0; i<SIZE; i++){
        for(j=0; j<SIZE; j++){
            printf("%i", board[i][j]);
        }
        printf("\n");
    }
}


scoreBoard(char board[SIZE][SIZE], int countX[SIZE], int countO[SIZE]);
printScores(char board[SIZE][SIZE]);
playGame(char board[SIZE][SIZE], char player1,char player2);

int main(void){
    int board[SIZE][SIZE];
    return 0;
}
