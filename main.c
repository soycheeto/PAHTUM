#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define SIZE 7

void printBoard(char board[SIZE][SIZE]);
bool isValidMove(char board[SIZE][SIZE], int row, int col);
void playMove(char board[SIZE][SIZE], char player, int *x, int *y);
void initializeBoard(char board[SIZE][SIZE]);
void scoreBoard(char board[SIZE][SIZE], int countX[5], int countO[5]);
void printScores(int countX[5], int countO[5]);
void playGame(char board[SIZE][SIZE], char player1, char player2);

void printBoard(char board[SIZE][SIZE]) {
    printf("    ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d   ", i);
    }
    printf("\n");
    printf("  ");
    for (int i = 0; i <= SIZE * 4; i++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  ");
    for (int i = 0; i <= SIZE * 4; i++) {
        printf("-");
    }
    printf("\n");
}

bool isValidMove(char board[SIZE][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

void playMove(char board[SIZE][SIZE], char player, int *x, int *y) {
    int row, col;
    int countX[5], countO[5];
    scoreBoard(board, countX, countO);
    //THIS FUNCTION WILL BE USED TO TRIGGER THE FIRST IF CONDITION WHERE IF COUNTX[0]<=COUNTO[0]: FULL OFFENSE  
    if(countX[0]<=countO[0]){
            //offense
    }

    void simulateOffense(char board[SIZE][SIZE], char player, int* x, int* y) {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (isValidMove(board, row, col)) {
                    board[row][col] = player; // Simulate placing the mark
                    int countX[5], countO[5];
                    scoreBoard(board, countX, countO);
                    bool hasTwoEmpties = false;

                    if (player == 'X' && 
                        ((col > 1 && board[row][col - 1] == ' ') || // Check left
                        (col < SIZE - 2 && board[row][col + 1] == ' ') || // Check right
                        (row > 1 && board[row - 1][col] == ' ') || // Check up
                        (row < SIZE - 2 && board[row + 1][col] == ' '))) { // Check down
                        hasTwoEmpties = true;
                    } else if (player == 'O' &&
                            ((col > 1 && board[row][col - 1] == ' ') || // Check left
                                (col < SIZE - 2 && board[row][col + 1] == ' ') || // Check right
                                (row > 1 && board[row - 1][col] == ' ') || // Check up
                                (row < SIZE - 2 && board[row + 1][col] == ' '))) { // Check down
                        hasTwoEmpties = true;
                    }

                    if (hasTwoEmpties) {
                        *x = row;
                        *y = col;
                        printf("\nLast move x: %d, y: %d\n", *x, *y);
                        board[row][col] = ' '; // Undo the simulation
                        return;
                    }
                    board[row][col] = ' '; // Undo the simulation
                }
            }
        }
    }



    //int total_x, total_o;  
    // void count_x_and_o(char board[][SIZE], int *total_x, int *total_o) {
    //     *total_x = 0;
    //     *total_o = 0;
    
    //     for (int i = 0; i < SIZE; i++) {
    //         for (int j = 0; j < SIZE; j++) {
    //             if (board[i][j] == 'X') {
    //                 (*total_x)++;
    //                 } else if (board[i][j] == 'O') {
    //                 (*total_o)++;
    //             }
    //         }
    //     }
    // }
    // count_x_and_o(board, &total_x, &total_o);

    //THIS FUNCTION RETURN VAL WILL BE USED TO TRIGGER THE SECOND IF CONDITION WHERE IF TOTAL EMPTY CELLS IS 10 (ARBITRARY NO.),: FULL OFFENSE
    int count_empty_cells(char board[][SIZE], int size) {
    int total_empty = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                total_empty++;
            }
        }
    }
    
    return total_empty;
    }


    bool hasChainOfLength(char player, int x, int y, int length){
        
        int dx[] = {1, 0}; // Possible directions: right, down
        int dy[] = {0, 1};
        for (int i = 0; i < 2; ++i) {
            int count = 1; // Count of consecutive player symbols
            int nx = x + dx[i], ny = y + dy[i];
            while (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == player) {
                count++;
                nx += dx[i];
                ny += dy[i];
            }
            nx = x - dx[i];
            ny = y - dy[i];
            while (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] == player) {
                count++;
                nx -= dx[i];
                ny -= dy[i];
            }
            if (count >= length) {
                return true;
            }
        }
        return false;
    }
    
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (isValidMove(board, row, col)) {
                board[row][col] = player;
                char opponent = (player == 'X') ? 'O' : 'X';
                if (hasChainOfLength(opponent, row, col, 3)) {
                    *x = row;
                    *y = col;
                    board[row][col] = ' ';
                    return;
                } else if (hasChainOfLength(opponent, row, col, 4)) {
                    *x = row;
                    *y = col;
                    board[row][col] = ' ';
                    return;
                } else if (hasChainOfLength(opponent, row, col, 5)) {
                    *x = row;
                    *y = col;
                    board[row][col] = ' ';
                    return;
                }
                board[row][col] = ' ';
            }
        }
    }
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isValidMove(board, row, col));
    *x = row;
    *y = col;
}

void scoreBoard(char board[SIZE][SIZE], int countX[5], int countO[5]) {
    for (int i = 0; i < 5; i++) {
        countX[i] = 0;
        countO[i] = 0;
    }
    for (int i = 0; i < SIZE; i++) {
        int countXCurrent = 0, countOCurrent = 0;
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 'X') {
                countXCurrent++;
                countOCurrent = 0;
            } else if (board[i][j] == 'O') {
                countOCurrent++;
                countXCurrent = 0;
            } else {
                if (countOCurrent >= 3) {
                    countO[countOCurrent - 3]++;
                } else if (countXCurrent >= 3) {
                    countX[countXCurrent - 3]++;
                }
                countXCurrent = 0;
                countOCurrent = 0;
            }
        }
        if (countOCurrent >= 3) {
            countO[countOCurrent - 3]++;
        } else if (countXCurrent >= 3) {
            countX[countXCurrent - 3]++;
        }
    }
    for (int j = 0; j < SIZE; j++) {
        int countXCurrent = 0, countOCurrent = 0;
        for (int i = 0; i < SIZE; i++) {
            if (board[i][j] == 'X') {
                countXCurrent++;
                countOCurrent = 0;
            } else if (board[i][j] == 'O') {
                countOCurrent++;
                countXCurrent = 0;
            } else {
                if (countOCurrent >= 3) {
                    countO[countOCurrent - 3]++;
                } else if (countXCurrent >= 3) {
                    countX[countXCurrent - 3]++;
                }
                countXCurrent = 0;
                countOCurrent = 0;
            }
        }
        if (countOCurrent >= 3) {
            countO[countOCurrent - 3]++;
        } else if (countXCurrent >= 3) {
            countX[countXCurrent - 3]++;
        }
    }
}

void printScores(int countX[5], int countO[5]) {
    int scoreX = 0, scoreO = 0;
    printf("\nBreakdown of Scores:\n");
    printf("Player X: ");
    for (int i = 0; i < 5; i++) {
        printf("%d sequence of %d, ", countX[i], i + 3);
        scoreX += countX[i] * ((i + 3 == 3) ? 3 : (i + 3 == 4) ? 10 : (i + 3 == 5) ? 25 : (i + 3 == 6) ? 56 : 119);
    }
    printf("\n");
    printf("Player O: ");
    for (int i = 0; i < 5; i++) {
        printf("%d sequence of %d, ", countO[i], i + 3);
        scoreO += countO[i] * ((i + 3 == 3) ? 3 : (i + 3 == 4) ? 10 : (i + 3 == 5) ? 25 : (i + 3 == 6) ? 56 : 119);
    }
    printf("\n");
    printf("Score for Player X: %d\n", scoreX);
    printf("Score for Player O: %d\n", scoreO);
}

void playGame(char board[SIZE][SIZE], char player1, char player2) {
    char currentPlayer = player1;
    int moves = 0;
    initializeBoard(board);
    int countX[5], countO[5];
    int row = -1, col = -1;
    while (moves < SIZE * SIZE) {
        printf("\nCurrent Board:\n");
        printBoard(board);
        scoreBoard(board, countX, countO);
        printScores(countX, countO);
        if (currentPlayer == player1) {
            row = -1;
            col = -1;
            playMove(board, currentPlayer, &row, &col);
            if (isValidMove(board, row, col)) {
                board[row][col] = currentPlayer;
            }
            if (row != -1 && col != -1) {
                printf("Player %c plays at %d %d\n", currentPlayer, row, col);
            }
        } else {
            do {
                printf("Enter your move (row col): ");
                scanf("%d %d", &row, &col);
            } while (!isValidMove(board, row, col));
            board[row][col] = currentPlayer;
        }
        moves++;
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE], player1 = 'X', player2 = 'O';
    playGame(board, player1, player2);
    printf("\nFinal Board: \n");
    printBoard(board);
    int countX[5], countO[5];
    scoreBoard(board, countX, countO);
    printScores(countX, countO);
    return 0;
}
