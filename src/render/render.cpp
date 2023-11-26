#include "render.h"

#include <ncurses.h>

#include <array>

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

  init_pair(WordleColor::BACKGROUND, WordleColor::BACKGROUND,
            WordleColor::BACKGROUND);
  init_pair(WordleColor::GRAY, WordleColor::WHITE, WordleColor::GRAY);
  init_pair(WordleColor::LIGHT_GRAY, WordleColor::WHITE,
            WordleColor::LIGHT_GRAY);
  init_pair(WordleColor::WHITE, WordleColor::WHITE, WordleColor::BACKGROUND);
  init_pair(WordleColor::YELLOW, WordleColor::WHITE, WordleColor::YELLOW);
  init_pair(WordleColor::GREEN, WordleColor::WHITE, WordleColor::GREEN);
}

Render::~Render() { endwin(); }

void Render::startColor(WordleColor color) { attron(COLOR_PAIR(color)); }

void Render::stopColor(WordleColor color) { attroff(COLOR_PAIR(color)); }

short Render::scaleRGB(int rgb) { return (rgb / 255.0) * 1000.0; }

void Render::drawTitle() {
  /*
    __      __                .___.__
  /  \    /  \___________  __| _/|  |   ____
  \   \/\/   /  _ \_  __ \/ __ | |  | _/ __ \
  \        (  <_> )  | \/ /_/ | |  |_\  ___/
    \__/\  / \____/|__|  \____ | |____/\___  >
        \/                   \/           \/
  */

  startColor(WordleColor::WHITE);

  mvprintw(0, 36, " __      __                .___.__          ");
  mvprintw(1, 36, "/  \\    /  \\___________  __| _/|  |   ____  ");
  mvprintw(2, 36, "\\   \\/\\/   /  _ \\_  __ \\/ __ | |  | _/ __ \\ ");
  mvprintw(3, 36, " \\        (  <_> )  | \\/ /_/ | |  |_\\  ___/ ");
  mvprintw(4, 36, "  \\__/\\  / \\____/|__|  \\____ | |____/\\___  >");
  mvprintw(5, 36, "       \\/                   \\/           \\/ ");

  stopColor(WordleColor::WHITE);
}

void Render::drawBackground() {
  startColor(WordleColor::BACKGROUND);

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      mvaddch(i, j, EMPTY_CELL);
    }
  }

  stopColor(WordleColor::BACKGROUND);
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
            startColor(WordleColor::GREEN);
          } else if (cell->getState() == CellState::EXISTS) {
            startColor(WordleColor::YELLOW);
          } else {
            startColor(WordleColor::GRAY);
          }

          mvaddch(j + r * 4 + 1, i + c * 7 + 2,
                  (i == 2 && j == 1) ? cell->getLetter() : EMPTY_CELL);

          stopColor(WordleColor::GRAY);
          stopColor(WordleColor::YELLOW);
          stopColor(WordleColor::GREEN);
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
    startColor(WordleColor::GREEN);
  } else if (game->getState() == GameState::LOST) {
    result = "You lost! The word was " + game->getWord() + ".";
    startColor(WordleColor::YELLOW);
  } else {
    startColor(WordleColor::GRAY);
  }

  for (int c = 0; c < 33; c++) {
    for (int r = 0; r < 2; r++) {
      mvaddch(r + 21, c + 2, EMPTY_CELL);
    }
  }

  mvprintw(21, 2 + (33 - result.length()) / 2, result.c_str());

  if (game->getState() != GameState::PLAYING) {
    mvprintw(22, 2 + (33 - 26) / 2, "Hit any key for a new word...");
  }

  stopColor(WordleColor::GREEN);
  stopColor(WordleColor::YELLOW);
  stopColor(WordleColor::GRAY);
}

void Render::render() {
  erase();

  this->drawBackground();
  this->drawTitle();
  this->drawBoard();
  this->drawResult();

  refresh();
}