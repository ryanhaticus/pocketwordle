#include "word.h"

std::string chooseRandomWord() {
  int randomIndex = rand() % words.size();

  return words[randomIndex];
}