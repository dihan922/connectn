#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "move.h"

int getValidColumn(char** board, int num_cols) {
    /**
    makes sure a user chosen column is on the board and not full
    @board: the board with all the pieces
    @num_cols: the number of columns on the board
    @returns: the index of the chosen column
    */
    int chosenColumn;
    bool isValid = false;
    char input[50];

    while (!isValid) {
        printf("Enter a column between 0 and %d to play in: ", (num_cols - 1));
        if (fgets(input, sizeof input, stdin) != NULL) {
            if (sscanf (input, "%d", &chosenColumn) == 1) {
                if (chosenColumn >= 0 && chosenColumn < num_cols && board[0][chosenColumn] == '*') {
                    isValid = true;
                }
            }
        }
    }
    return chosenColumn;
}

void placePiece(char** board, int num_rows, int column, char piece) {
    /**
    places a piece on the highest point of a column
    @board: the board with all the pieces
    @num_rows: the number of rows in the board
    @column: the column the piece is being dropped into
    @piece: the piece being dropped
    @returns: nothing
    @modifies: the board
    */
    int row = num_rows - 1;
    while (board[row][column] != '*') {
        row--;
    }
    board[row][column] = piece;
}