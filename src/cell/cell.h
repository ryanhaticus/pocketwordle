#ifndef CELL_H
#define CELL_H

typedef enum { DOESNT_EXIST, EXISTS, GUESSED } CellState;

class Cell {
 private:
  int position;
  char letter = ' ';
  CellState state = CellState::DOESNT_EXIST;

 public:
  Cell(int position) { this->position = position; };
  ~Cell(){};

  char getLetter();
  int getPosition();
  CellState getState();

  void setLetter(char letter);

  void guess();

  void clear();

  bool isEmpty();
};

#endif