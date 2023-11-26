#include "board.h"

#include "../cell/cell.h"
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

CellState Board::findLetterState(char letter) {
  CellState state = CellState::DOESNT_EXIST;

  for (int i = 0; i < 5; i++) {
    Row* row = this->rows[i];

    for (int j = 0; j < 5; j++) {
      Cell* cell = row->getCell(j);

      if (cell->getLetter() != letter) {
        continue;
      }

      CellState thisState = cell->getState();

      if (thisState == CellState::GUESSED) {
        return CellState::GUESSED;
      }

      if (thisState == CellState::EXISTS && state == CellState::DOESNT_EXIST) {
        state = CellState::EXISTS;
      }
    }
  }

  return state;
}