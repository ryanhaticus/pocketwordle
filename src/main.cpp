#include <ncurses.h>

#include <cstdlib>
#include <ctime>

#include "./game/game.h"
#include "./render/render.h"

int main(int argc, char *argv[]) {
  srand(time(NULL));

  static Game *game = Game::getInstance();
  static Render *render = Render::getInstance();

  while (game->isRunning()) {
    render->render();

    char input = getch();
    game->move(input);
  }

  return 0;
}