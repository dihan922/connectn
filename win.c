#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "win.h"

bool horizontalWin(char** board, int row_dim, int col_dim, int amount_to_win) {
    /**
    checks if someone won with the horizontal (left to right) pattern
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    int count = 0;
    char* pieces = "XO";
    int piece = 0;

    for (int row = 0; row < row_dim; ++row) {
        count = 0;

        for (int col = 0; col < col_dim; ++col) {
            if (board[row][col] == pieces[piece]) {
                count++;
            }
            else if (board[row][col] != '*') {
                piece = !piece;
                count = 1;
            }
            else {
                count = 0;
            }
            
            if (count == amount_to_win) {
                return true;
            }
        }
    }

    return false;
}

bool verticalWin(char** board, int row_dim, int col_dim, int amount_to_win) {
    /**
    checks if someone won with the vertical (top to bottom) pattern
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    int count = 0;
    char* pieces = "XO";
    int piece = 0;

    for (int col = 0; col < col_dim; ++col) {
        count = 0;

        for (int row = 0; row < row_dim; ++row) {
            if (board[row][col] == pieces[piece]) {
                count++;
            }
            else if (board[row][col] != '*') {
                piece = !piece;
                count = 1;
            }
            else {
                count = 0;
            }
            
            if (count == amount_to_win) {
                return true;
            }
        }
    }

    return false;
}

bool checkLeftDiagonals(char** board, int row_dim, int col_dim, int row, int col, int amount_to_win) {
    /**
    checks a left diagonal, starting from a specific point, for a win
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @row: the row the specific point is in
    @col: the column the specific point is in
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    int count = 0;
    char* pieces = "XO";
    int piece = 0;

    int current_row = row;
    int current_col = col;

    do {
        if (board[current_row][current_col] == pieces[piece]) {
            count++;
        }
        else if (board[current_row][current_col] != '*') {
            piece = !piece;
            count = 1;
        }
        else {
            count = 0;
        }

        if (count == amount_to_win) {
            return true;
        }

        current_row++;
        current_col++;
    } while ((current_row + 1) <= row_dim && (current_col + 1) <= col_dim);
    return false;
}

bool checkRightDiagonals(char** board, int row_dim, int col_dim, int row, int col, int amount_to_win) {
    /**
    checks a right diagonal, starting from a specific point, for a win
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @row: the row the specific point is in
    @col: the column the specific point is in
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    int count = 0;
    char* pieces = "XO";
    int piece = 0;

    int current_row = row;
    int current_col = col;

    do {
        if (board[current_row][current_col] == pieces[piece]) {
            count++;
        }
        else if (board[current_row][current_col] != '*') {
            piece = !piece;
            count = 1;
        }
        else {
            count = 0;
        }

        if (count == amount_to_win) {
            return true;
        }

        current_row++;
        current_col--;
    } while ((current_row + 1) <= row_dim && current_col >= 0);
    return false;
}

bool leftDiagonalWin(char** board, int row_dim, int col_dim, int amount_to_win) {
    /**
    checks if someone won with the left diagonal (top left to bottom right) pattern
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    int corner_row = 0;
    int corner_col = 0;
    bool winDetected = false;

    for (corner_row = row_dim - 1; corner_row > 0; --corner_row) {
        winDetected = checkLeftDiagonals(board, row_dim, col_dim, corner_row, corner_col, amount_to_win);
        if (winDetected) {
            return winDetected;
        }
    }
    
    for (corner_col = 0; corner_col < col_dim; ++corner_col) {
        winDetected = checkLeftDiagonals(board, row_dim, col_dim, corner_row, corner_col, amount_to_win);
        if (winDetected) {
            return winDetected;
        }
    }

    return winDetected;
}

bool rightDiagonalWin(char** board, int row_dim, int col_dim, int amount_to_win) {
    /**
    checks if someone won with the right diagonal (bottom left to top right) pattern
    @board: the board with all the pieces
    @row_dim: the number of rows in the board
    @col_dim: the number of columns in the board
    @amount_to_win: the number of pieces needed in a row to win
    @returns: true if someone won, false if otherwise
    */
    int corner_row = 0;
    int corner_col = 0;
    bool winDetected = false;

    for (corner_col = 0; corner_col < col_dim - 1; ++corner_col) {
        winDetected = checkRightDiagonals(board, row_dim, col_dim, corner_row, corner_col, amount_to_win);
        if (winDetected) {
            return winDetected;
        }
    }
    
    for (corner_row = 0; corner_row < row_dim; ++corner_row) {
        winDetected = checkRightDiagonals(board, row_dim, col_dim, corner_row, corner_col, amount_to_win);
        if (winDetected) {
            return winDetected;
        }
    }

    return winDetected;
}