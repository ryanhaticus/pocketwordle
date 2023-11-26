#include "render.h"

#include <ncurses.h>

#include <array>
#include <string>
#include <vector>

#include "../board/board.h"
#include "../cell/cell.h"
#include "../game/game.h"
#include "../row/row.h"

Render *Render::instance = nullptr;

Render::Render() {
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);

  start_color();

  init_color(WordleColor::BACKGROUND, scaleRGB(18), scaleRGB(18), scaleRGB(19));
  init_color(WordleColor::GRAY, scaleRGB(58), scaleRGB(58), scaleRGB(60));
  init_color(WordleColor::LIGHT_GRAY, scaleRGB(128), scaleRGB(131),
             scaleRGB(132));
  init_color(WordleColor::WHITE, scaleRGB(255), scaleRGB(255), scaleRGB(255));
  init_color(WordleColor::YELLOW, scaleRGB(181), scaleRGB(159), scaleRGB(59));
  init_color(WordleColor::GREEN, scaleRGB(83), scaleRGB(141), scaleRGB(78));

  init_pair(WordleColorPair::CP_BACKGROUND, WordleColor::BACKGROUND,
            WordleColor::BACKGROUND);
  init_pair(WordleColorPair::CP_GRAY, WordleColor::WHITE, WordleColor::GRAY);
  init_pair(WordleColorPair::CP_LIGHT_GRAY, WordleColor::WHITE,
            WordleColor::LIGHT_GRAY);
  init_pair(WordleColorPair::CP_WHITE, WordleColor::WHITE,
            WordleColor::BACKGROUND);
  init_pair(WordleColorPair::CP_YELLOW, WordleColor::WHITE,
            WordleColor::YELLOW);
  init_pair(WordleColorPair::CP_GREEN, WordleColor::WHITE, WordleColor::GREEN);
  init_pair(WordleColorPair::CP_YELLOW_TEXT, WordleColor::YELLOW,
            WordleColor::BACKGROUND);
  init_pair(WordleColorPair::CP_GREEN_TEXT, WordleColor::GREEN,
            WordleColor::BACKGROUND);
}

Render::~Render() { endwin(); }

void Render::startColor(WordleColorPair color) { attron(COLOR_PAIR(color)); }

void Render::stopColor(WordleColorPair color) { attroff(COLOR_PAIR(color)); }

short Render::scaleRGB(int rgb) { return (rgb / 255.0) * 1000.0; }

void Render::drawTitle() {
  /*
___        _       _
| _ \___ __| |_____| |_
|  _/ _ / _| / / -_|  _|
__| \______|_\_\___|___|
\ \    / ___ _ _ __| | |___
\ \/\/ / _ | '_/ _` | / -_)
  \_/\_/\___|_| \__,_|_\___|
  */

  startColor(WordleColorPair::CP_GREEN_TEXT);
  mvprintw(0, 42, "  ___        _       _       ");
  mvprintw(1, 42, " | _ \\___ __| |_____| |_     ");
  mvprintw(2, 42, " |  _/ _ / _| / / -_|  _|    ");
  mvprintw(3, 42, "  __| \\______|_\\_\\___|___|   ");
  stopColor(WordleColorPair::CP_GREEN_TEXT);

  startColor(WordleColorPair::CP_YELLOW_TEXT);
  mvprintw(4, 42, "  \\ \\    / ___ _ _ __| | |___");
  mvprintw(5, 42, "   \\ \\/\\/ / _ | '_/ _` | / -_)");
  mvprintw(6, 42, "    \\_/\\_/\\___|_| \\__,_|_\\___|");
  stopColor(WordleColorPair::CP_YELLOW_TEXT);

  startColor(WordleColorPair::CP_WHITE);
  mvprintw(7, 42, "        By Ryan Huellen        ");
  stopColor(WordleColorPair::CP_WHITE);
}

void Render::drawBackground() {
  startColor(WordleColorPair::CP_BACKGROUND);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      mvaddch(i, j, EMPTY_CELL);
    }
  }

  stopColor(WordleColorPair::CP_BACKGROUND);
}

void Render::drawBoard() {
  Game *game = Game::getInstance();

  for (int r = 0; r < 5; r++) {
    Row *row = game->getBoard()->getRow(r);

    for (int c = 0; c < 5; c++) {
      Cell *cell = row->getCell(c);

      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
          if (cell->getState() == CellState::GUESSED) {
            startColor(WordleColorPair::CP_GREEN);
          } else if (cell->getState() == CellState::EXISTS) {
            startColor(WordleColorPair::CP_YELLOW);
          } else {
            startColor(WordleColorPair::CP_GRAY);
          }

          mvaddch(j + r * 4 + 1, i + c * 7 + 2,
                  (i == 2 && j == 1) ? cell->getLetter() : EMPTY_CELL);

          stopColor(WordleColorPair::CP_GRAY);
          stopColor(WordleColorPair::CP_YELLOW);
          stopColor(WordleColorPair::CP_GREEN);
        }
      }
    }
  }
}

void Render::drawResult() {
  static Game *game = Game::getInstance();

  std::string result = "";

  if (game->getState() == GameState::WON) {
    result = "You won!";
    startColor(WordleColorPair::CP_GREEN);
  } else if (game->getState() == GameState::LOST) {
    result = "You lost! The word was " + game->getWord() + ".";
    startColor(WordleColorPair::CP_YELLOW);
  } else {
    startColor(WordleColorPair::CP_GRAY);
  }

  for (int c = 0; c < 77; c++) {
    for (int r = 0; r < 2; r++) {
      mvaddch(r + 21, c + 2, EMPTY_CELL);
    }
  }

  mvprintw(21, 2 + (77 - result.length()) / 2, result.c_str());

  if (game->getState() != GameState::PLAYING) {
    mvprintw(22, 2 + (77 - 26) / 2, "Hit any key for a new word...");
  }

  stopColor(WordleColorPair::CP_GREEN);
  stopColor(WordleColorPair::CP_YELLOW);
  stopColor(WordleColorPair::CP_GRAY);
}

std::array<std::vector<std::string>, 3> qwertyKeyboard = {
    {{"Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P"},
     {"A", "S", "D", "F", "G", "H", "J", "K", "L"},
     {"ENTER", "Z", "X", "C", "V", "B", "N", "M", "BACK"}}};

void Render::drawKeyboard() {
  static Game *game = Game::getInstance();

  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < qwertyKeyboard[r].size(); c++) {
      std::string key = qwertyKeyboard[r][c];

      CellState keyState = CellState::DOESNT_EXIST;

      if (key.size() == 1) {
        keyState = game->getBoard()->findLetterState(key[0]);
      }

      switch (keyState) {
        case CellState::GUESSED:
          startColor(WordleColorPair::CP_GREEN);
          break;
        case CellState::EXISTS:
          startColor(WordleColorPair::CP_YELLOW);
          break;
        default:
          startColor(WordleColorPair::CP_LIGHT_GRAY);
          break;
      }

      int padding =
          (r == 0 ? 2 : 0) + (r == 1 ? 4 : 0) + (r == 2 && c > 0 ? 4 : 0);

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < key.length() + 2; j++) {
          mvaddch(i + 9 + r * 4, j + c * 4 + 37 + padding, EMPTY_CELL);
        }
      }

      mvprintw(10 + r * 4, c * 4 + 38 + padding, key.c_str());

      stopColor(WordleColorPair::CP_LIGHT_GRAY);
      stopColor(WordleColorPair::CP_YELLOW);
      stopColor(WordleColorPair::CP_GREEN);
    }
  }
}

void Render::drawLeftBar() {
  static Game *game = Game::getInstance();

  for (int i = 0; i < 24; i++) {
    if (game->getState() == GameState::WON) {
      startColor(WordleColorPair::CP_GREEN);
    } else if (game->getState() == GameState::LOST) {
      startColor(WordleColorPair::CP_YELLOW);
    } else {
      startColor(WordleColorPair::CP_GRAY);
    }

    mvaddch(i, 0, EMPTY_CELL);

    stopColor(WordleColorPair::CP_GRAY);
    stopColor(WordleColorPair::CP_YELLOW);
    stopColor(WordleColorPair::CP_GREEN);
  }
}

void Render::render() {
  erase();

  this->drawBackground();
  this->drawTitle();
  this->drawBoard();
  this->drawResult();
  this->drawKeyboard();
  this->drawLeftBar();

  refresh();
}