#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int i, j;
    int container[10] = {0};

    for (i = 0; i < 9; i++) {
        memset(container, 0, sizeof(int) * 10);

        for (j = 0; j < 9; j++) {
            if (board[i][j] == '.')
                continue;

            int num = (int) (board[i][j] - '0');
            if (container[num] == 1)
                return false;
            else
                container[num] = 1;
        }
    }

    for (j = 0; j < 9; j++) {
        memset(container, 0, sizeof(int) * 10);

        for (i = 0; i < 9; i++) {
            if (board[i][j] == '.')
                continue;

            int num = (int) (board[i][j] - '0');
            if (container[num] == 1)
                return false;
            else
                container[num] = 1;
        }
    }

    int x, y;
    for (x = 0; x < 9; x+=3) {
        for (y = 0; y < 9; y+=3) {
            memset(container, 0, sizeof(int) * 10);

            for (i = x; i < x+3; i++) {
                for (j = y; j < y+3; j++) {
                    if (board[i][j] == '.')
                        continue;

                    int num = (int) (board[i][j] - '0');
                    if (container[num] == 1)
                        return false;
                    else
                        container[num] = 1;
                }
            }
        }
    }

    return true;
}

int main() {
    char row1[] = {'8', '3', '.', '.', '7', '.', '.', '.', '.'};
    char row2[] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    char row3[] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    char row4[] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    char row5[] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    char row6[] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    char row7[] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    char row8[] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    char row9[] = {'.', '.', '.', '.', '8', '.', '.', '.', '9'};
    char *board[] = {row1, row2, row3, row4, row5, row6, row7, row8, row9};
    int boardSize = 9;
    int boardColSize[] = {9, 9, 9, 9, 9, 9, 9, 9, 9};

    printf("%d\n", isValidSudoku(board, boardSize, boardColSize));
}
