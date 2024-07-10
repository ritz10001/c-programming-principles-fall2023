// Online C compiler to run C program online
#include <stdio.h>

typedef struct {
    int number_of_moves;
    int is_in_check;
} white;
typedef struct {
    int number_of_moves;
    int is_in_check;
} black;

typedef struct {
    white Player1;
    black Player2;
    int[8][8] board;
    int is_game_over;
} Chess;

int game_over(Chess chess) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess.board[i][j] == 6 || chess.board[i][j] == -6) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    // Write C code here
    printf("Hello world");
    Chess game;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            game.board[i][j] = 6;
        }
    }
    if (game_over(game)) {
        printf("Game Over");
    }
    return 0;
}