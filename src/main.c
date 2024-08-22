#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char letter;
  int wordMultiplier;
  int letterMultiplier;
} Cell;

typedef struct {
  Cell cells[15][15];
} Board;

typedef enum { HORIZONTAL, VERTICAL } Orientation;

typedef struct {
  char *word;
  int x;
  int y;
  Orientation orientation;
} Move;

int letterDistribution[27] = {
    9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2,
    6, 8, 2, 1, 6,  4, 6, 4, 2, 2, 1, 2, 1,
    2 // Blank
};

int pointValues[27] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10,
    0 // Blank
};

char *letterMultiplier[15] = {
    "   2       2   ", "     3   3     ", "      2 2      ", "2      2      2",
    "               ", " 3   3   3   3 ", "  2   2 2   2  ", "   2   .   2   ",
    "  2   2 2   2  ", " 3   3   3   3 ", "               ", "2      2      2",
    "      2 2      ", "     3   3     ", "   2       2   ",
};

char *wordMultiplier[15] = {
    "3      3      3", " 2           2 ", "  2         2  ", "   2       2   ",
    "    2     2    ", "               ", "               ", "3      .      3",
    "               ", "               ", "    2     2    ", "   2       2   ",
    "  2         2  ", " 2           2 ", "3      3      3",
};

void displayBoard(Board *board) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      if (board->cells[i][j].letter) {
        printf("%c", board->cells[i][j].letter);
      } else if (letterMultiplier[i][j] == '2') {
        printf("2");
      } else if (letterMultiplier[i][j] == '3') {
        printf("3");
      } else if (wordMultiplier[i][j] == '2') {
        printf("2");
      } else if (wordMultiplier[i][j] == '3') {
        printf("3");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

Board *initializeBoard() {
  Board *board = malloc(sizeof(Board));
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      board->cells[i][j].letter = 0;
      board->cells[i][j].wordMultiplier = 1;
      board->cells[i][j].letterMultiplier = 1;
      if (letterMultiplier[i][j] == '2') {
        board->cells[i][j].letterMultiplier = 2;
      } else if (letterMultiplier[i][j] == '3') {
        board->cells[i][j].letterMultiplier = 3;
      }

      if (wordMultiplier[i][j] == '2') {
        board->cells[i][j].wordMultiplier = 2;
      } else if (wordMultiplier[i][j] == '3') {
        board->cells[i][j].wordMultiplier = 3;
      }
    }
  }
  return board;
}

int main() {
  char *wordListFile = "/usr/share/dict/words";

  Board *board = initializeBoard();
  board->cells[0][1].letter = 'A';

  displayBoard(board);
}
