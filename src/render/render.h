#ifndef RENDER_H
#define RENDER_H

#define WIDTH 80
#define HEIGHT 21

typedef enum { BACKGROUND, GRAY, LIGHT_GRAY, WHITE, YELLOW, GREEN } WordleColor;

class Render {
 private:
  static Render *instance;

  Render();
  ~Render();

  void startColor(WordleColor color);
  void stopColor(WordleColor color);
  short scaleRGB(int rgb);
  void drawBackground();
  void drawTitle();
  void drawBoard();
  void drawResult();

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