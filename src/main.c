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

int main() {
  char *wordListFile = "/usr/share/dict/words";
}
