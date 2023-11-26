#ifndef CURSOR_H
#define CURSOR_H

class Cursor {
 private:
  int row = 0;
  int col = 0;

 public:
  Cursor(){};
  ~Cursor(){};
  int getRow();
  int getCol();
  void progressRow();
  void progressCol();
  void regressCol();
  void reset();
};

#endif