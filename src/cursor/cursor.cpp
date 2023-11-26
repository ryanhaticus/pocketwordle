#include "cursor.h"

int Cursor::getRow() { return this->row; }

int Cursor::getCol() { return this->col; }

void Cursor::progressCol() {
  if (this->col < 4) {
    this->col++;
  }
}

void Cursor::regressCol() {
  if (this->col > 0) {
    this->col--;
  }
}

void Cursor::progressRow() {
  if (this->row < 4) {
    this->row++;
    this->col = 0;
  }
}

void Cursor::reset() {
  this->row = 0;
  this->col = 0;
}
