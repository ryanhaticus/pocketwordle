#ifndef RENDER_H
#define RENDER_H

#define WIDTH 80
#define HEIGHT 21

typedef enum { BACKGROUND, GRAY, LIGHT_GRAY, WHITE, YELLOW, GREEN } WordleColor;

typedef enum {
  CP_BACKGROUND,
  CP_GRAY,
  CP_LIGHT_GRAY,
  CP_WHITE,
  CP_YELLOW,
  CP_GREEN,
  CP_YELLOW_TEXT,
  CP_GREEN_TEXT
} WordleColorPair;

class Render {
 private:
  static Render *instance;

  Render();
  ~Render();

  void startColor(WordleColorPair color);
  void stopColor(WordleColorPair color);
  short scaleRGB(int rgb);
  void drawBackground();
  void drawTitle();
  void drawBoard();
  void drawResult();
  void drawKeyboard();
  void drawLeftBar();

 public:
  static Render *getInstance() {
    if (!instance) {
      instance = new Render();
    }

    return instance;
  }
  void render();
};

#endif