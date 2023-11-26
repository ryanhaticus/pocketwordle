#ifndef ROW_H
#define ROW_H

#include <array>

#include "../cell/cell.h"

class Row {
 private:
  std::array<Cell*, 5> cells;

 public:
  Row() {
    for (int i = 0; i < 5; i++) {
      this->cells[i] = new Cell(i);
    }
  }
  ~Row() {}

  Cell* getCell(int i);
  void clear();
  void guess();
  bool isCorrect();
};

#endif