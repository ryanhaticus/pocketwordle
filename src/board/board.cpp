#include "board.h"

#include "../row/row.h"

Row* Board::getRow(int i) { return this->rows[i]; }

void Board::clear() {
  for (int i = 0; i < 5; i++) {
    Row* row = this->rows[i];
    row->clear();
  }
}

void Board::setLetter(int row, int col, char letter) {
  Row* r = this->rows[row];

  r->getCell(col)->setLetter(letter);
}