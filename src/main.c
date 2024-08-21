#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char letter;
  int wordMultiplier;
  int letterMultiplier;
} Cell;

typedef struct {
  Cell cells[15][15];
} Board;

int letterDistribution[27] = {
    9,  // A
    2,  // B
    2,  // C
    4,  // D
    12, // E
    2,  // F
    3,  // G
    2,  // H
    9,  // I
    1,  // J
    1,  // K
    4,  // L
    2,  // M
    6,  // N
    8,  // O
    2,  // P
    1,  // Q
    6,  // R
    4,  // S
    6,  // T
    4,  // U
    2,  // V
    2,  // W
    1,  // X
    2,  // Y
    1,  // Z
    2   // Blank
};

char *letterMultiplier[15] = {
  "   2       2   ",
  "     3   3     ",
  "      2 2      ",
  "2      2      2",
  "               ",
  " 3   3   3   3 ",
  "  2   2 2   2  ",
  "   2   .   2   ",
  "  2   2 2   2  ",
  " 3   3   3   3 ",
  "               ",
  "2      2      2",
  "      2 2      ",
  "     3   3     ",
  "   2       2   ",
};

char *wordMultiplier[15] = {
  "3      3      3",
  " 2           2 ",
  "  2         2  ",
  "   2       2   ",
  "    2     2    ",
  "               ",
  "               ",
  "3      .      3",
  "               ",
  "               ",
  "    2     2    ",
  "   2       2   ",
  "  2         2  ",
  " 2           2 ",
  "3      3      3",
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
