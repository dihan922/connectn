#ifndef WIN_H
#define WIN_H

    bool horizontalWin(char** board, int row_dim, int col_dim, int amount_to_win);
    bool verticalWin(char** board, int row_dim, int col_dim, int amount_to_win);
    bool checkLeftDiagonals(char** board, int row_dim, int col_dim, int row, int col, int amount_to_win);
    bool checkRightDiagonals(char** board, int row_dim, int col_dim, int row, int col, int amount_to_win);
    bool leftDiagonalWin(char** board, int row_dim, int col_dim, int amount_to_win);
    bool rightDiagonalWin(char** board, int row_dim, int col_dim, int amount_to_win);

#endif