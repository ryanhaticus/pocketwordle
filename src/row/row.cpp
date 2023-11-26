#include "row.h"

Cell* Row::getCell(int i) { return this->cells[i]; }

void Row::clear() {
  for (int i = 0; i < 5; i++) {
    Cell* cell = this->cells[i];
    cell->clear();
  }
}

void Row::guess() {
  for (int i = 0; i < 5; i++) {
    Cell* cell = this->cells[i];
    cell->guess();
  }
}

bool Row::isCorrect() {
  for (int i = 0; i < 5; i++) {
    Cell* cell = this->cells[i];
    if (cell->getState() != CellState::GUESSED) {
      return false;
    }
  }

  return true;
}