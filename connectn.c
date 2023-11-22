// This program creates a 2 player game of Connect-N (Connect-4, but the board dimensions and amount of pieces needed in a row to win is decided by the user)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "connectn.h"
#include "board.h"
#include "move.h"
#include "win.h"

bool gameIsOver(char** board, int row_dim, int col_dim, int amount_to_win) {
    /**
    checks if someone won the game
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    return horizontalWin(board, row_dim, col_dim, amount_to_win) || verticalWin(board, row_dim, col_dim, amount_to_win) || rightDiagonalWin(board, row_dim, col_dim, amount_to_win) || leftDiagonalWin(board, row_dim, col_dim, amount_to_win);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else if (argc > 4) {
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    else {
        const int num_rows = atoi(argv[1]);
        const int num_cols = atoi(argv[2]);
        const int amount_to_win = atoi(argv[3]);

        int moveCount = 0;
        int moveToFillBoard = num_rows * num_cols;
        char* pieces = "XO";
        
        char** board = make_board(num_rows, num_cols);
        display_board(board, num_rows, num_cols);

        while (moveCount != moveToFillBoard) {
            if (moveCount >= (amount_to_win * 2 - 1) && gameIsOver(board, num_rows, num_cols, amount_to_win)) {
                printf("Player %d Won!\n", ((moveCount - 1) % 2) + 1);
                exit(0);
            }
            int chosenColumn = getValidColumn(board, num_cols);
            placePiece(board, num_rows, chosenColumn, pieces[moveCount % 2]);
            display_board(board, num_rows, num_cols);
            moveCount++;
        }
        printf("Tie game!\n");
    }
    
    return 0;
}