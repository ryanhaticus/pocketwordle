#ifndef GAME_H
#define GAME_H

#define EMPTY_CELL ' '

#include <string>

#include "../board/board.h"
#include "../cell/cell.h"
#include "../cursor/cursor.h"
#include "../word/word.h"

typedef enum {
  PLAYING,
  WON,
  LOST,
} GameState;

class Game {
 private:
  static Game *instance;

  bool running = true;
  GameState state = GameState::PLAYING;
  std::string word;
  Board *board = new Board();
  Cursor *cursor = new Cursor();

  Game() { this->setWord(chooseRandomWord()); };
  ~Game(){};

 public:
  static Game *getInstance() {
    if (!instance) {
      instance = new Game();
    }

    return instance;
  }

  bool isRunning();
  void stop();

  std::string getWord();
  void setWord(std::string word);

  Board *getBoard();

  void move(char input);

  GameState getState();
};

#endif