#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"

char** make_board(int row_dim, int col_dim) {
    /**
    creates an empty board
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @returns: a row_dim X col_dim board
    */
    char** board = (char**)malloc(row_dim * sizeof(char*));
    for (int i = 0; i < row_dim; ++i) {
        board[i] = (char*)malloc(col_dim * sizeof(char));
    }
    for (int i = 0; i < row_dim; ++i) {
        for (int j = 0; j < col_dim; ++j) {
            board[i][j] = '*';
        }
    }
    return board;
}

void display_board(char** board, int row_dim, int col_dim) {
    /**
    prints a board to the screen
    @board: the board being displayed
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @returns: nothing
    */
    int row_num = row_dim - 1;

    for (int i = 0; i < row_dim; ++i) {
        printf("%d ", row_num);
        for (int j = 0; j < col_dim; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
        row_num--;
    }
    printf("  ");
    for (int i = 0; i < col_dim; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}