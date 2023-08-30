#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool checkBoundary(int rowSize, int colSize, int nextRow, int nextCol, int ** usedMap, char ** board, char cha) {
    if (nextRow < 0
        || nextCol < 0
        || nextRow >= rowSize
        || nextCol >= colSize
        || usedMap[nextRow][nextCol]
        || board[nextRow][nextCol] != cha
    ) {
        return false;
    }

    return true;
}

bool dfs(char ** board, int ** usedMap, int rowSize, int colSize, char * word, int wordIndex, int rowIndex, int colIndex) {
    if (word[wordIndex] == 0)
        return true;

    int nextRow, nextCol;

    nextRow = rowIndex-1;
    nextCol = colIndex;
    if (checkBoundary(rowSize, colSize, nextRow, nextCol, usedMap, board, word[wordIndex])) {
        usedMap[nextRow][nextCol] = 1;
        if (dfs(board, usedMap, rowSize, colSize, word, wordIndex+1, nextRow, nextCol))
            return true;
        usedMap[nextRow][nextCol] = 0;
    }

    nextRow = rowIndex;
    nextCol = colIndex-1;
    if (checkBoundary(rowSize, colSize, nextRow, nextCol, usedMap, board, word[wordIndex])) {
        usedMap[nextRow][nextCol] = 1;
        if (dfs(board, usedMap, rowSize, colSize, word, wordIndex+1, nextRow, nextCol))
            return true;
        usedMap[nextRow][nextCol] = 0;
    }

    nextRow = rowIndex+1;
    nextCol = colIndex;
    if (checkBoundary(rowSize, colSize, nextRow, nextCol, usedMap, board, word[wordIndex])) {
        usedMap[nextRow][nextCol] = 1;
        if (dfs(board, usedMap, rowSize, colSize, word, wordIndex+1, nextRow, nextCol))
            return true;
        usedMap[nextRow][nextCol] = 0;
    }

    nextRow = rowIndex;
    nextCol = colIndex+1;
    if (checkBoundary(rowSize, colSize, nextRow, nextCol, usedMap, board, word[wordIndex])) {
        usedMap[nextRow][nextCol] = 1;
        if (dfs(board, usedMap, rowSize, colSize, word, wordIndex+1, nextRow, nextCol))
            return true;
        usedMap[nextRow][nextCol] = 0;
    }

    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word) {
    int ** usedMap = (int **) malloc(sizeof(int *) * boardSize);
    int i, j,
        rowMemorySize = sizeof(int) * boardColSize[0];
    for (i = 0; i < boardSize; i++) {
        usedMap[i] = (int *) malloc(rowMemorySize);
        memset(usedMap[i], 0, rowMemorySize);
    }

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == word[0]) {
                usedMap[i][j] = 1;
                if (dfs(board, usedMap, boardSize, boardColSize[0], word, 1, i, j))
                    return true;
                usedMap[i][j] = 0;
            }
        }
    }

    return false;
}

int main() {
    char row1[] = {'A', 'B', 'C', 'E'};
    char row2[] = {'S', 'F', 'C', 'S'};
    char row3[] = {'A', 'D', 'E', 'E'};
    char *board[] = {row1, row2, row3};
    int boardColSize[] = {4,4,4};
    char * word = "ABCCED";

    printf("%d\n", exist(board, 3, boardColSize, word));
    return 0;
}
