#ifndef BOARD_H
#define BOARD_H

#include <array>

#include "../cell/cell.h"
#include "../row/row.h"

class Board {
 private:
  std::array<Row*, 5> rows;

 public:
  Board() {
    for (int i = 0; i < 5; i++) {
      this->rows[i] = new Row();
    }
  }
  ~Board() {}

  Row* getRow(int i);
  void clear();
  void setLetter(int row, int col, char letter);
};

#endif