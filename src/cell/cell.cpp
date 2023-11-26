#include "cell.h"

#include <string>

#include "../game/game.h"

char Cell::getLetter() { return this->letter; }

int Cell::getPosition() { return this->position; }

CellState Cell::getState() { return this->state; }

void Cell::setLetter(char letter) { this->letter = letter; }

void Cell::guess() {
  static Game *game = Game::getInstance();

  std::string word = game->getWord();

  if (word.find(this->letter) != std::string::npos) {
    this->state = CellState::EXISTS;
  } else {
    this->state = CellState::DOESNT_EXIST;
  }

  if (word.at(this->position) == this->letter) {
    this->state = CellState::GUESSED;
  }
}

void Cell::clear() {
  this->letter = EMPTY_CELL;
  this->state = CellState::DOESNT_EXIST;
}

bool Cell::isEmpty() { return this->letter == EMPTY_CELL; }