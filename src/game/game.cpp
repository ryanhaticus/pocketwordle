#include "game.h"

#include <ncurses.h>

#include "../board/board.h"
#include "../cell/cell.h"
#include "../cursor/cursor.h"
#include "../word/word.h"

Game *Game::instance = nullptr;

bool Game::isRunning() { return this->running; }

void Game::stop() { this->running = false; }

std::string Game::getWord() { return this->word; }

void Game::setWord(std::string word) {
  this->board->clear();

  for (size_t i = 0; i < word.length(); i++) {
    word[i] = toupper(word[i]);
  }

  this->word = word;
}

Board *Game::getBoard() { return this->board; }

void Game::move(char input) {
  if (input == 27) {
    this->stop();
    return;
  }

  Board *board = this->getBoard();
  Cursor *cursor = this->cursor;

  if (this->state != GameState::PLAYING) {
    board->clear();
    cursor->reset();
    this->state = GameState::PLAYING;
    this->setWord(chooseRandomWord());

    return;
  }

  Row *row = board->getRow(cursor->getRow());

  Cell *cell = row->getCell(cursor->getCol());

  if (input == 10 && cursor->getCol() == 4 && !cell->isEmpty()) {
    row->guess();

    if (row->isCorrect()) {
      this->state = GameState::WON;
      return;
    }

    if (cursor->getRow() == 4) {
      this->state = GameState::LOST;
      return;
    }

    cursor->progressRow();

    return;
  }

  if (input == KEY_BACKSPACE) {
    if (cell->getLetter() == EMPTY_CELL) {
      cursor->regressCol();
      cell = board->getRow(cursor->getRow())->getCell(cursor->getCol());
      cell->clear();
    } else {
      cell->clear();
    }

    return;
  }

  char letter = toupper(input);

  if (letter < 'A' || letter > 'Z') {
    return;
  }

  if (cursor->getCol() == 4 && cell->getLetter() != EMPTY_CELL) {
    return;
  }

  board->setLetter(cursor->getRow(), cursor->getCol(), letter);
  cursor->progressCol();
}

GameState Game::getState() { return this->state; }