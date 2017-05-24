#pragma once
#include "Chopter.hpp"
#include "Map.hpp"


class Game {
  unsigned long long int steps;
  int verticalChopterSteps;
  int horizontalChopterSteps;
  int blockWidth;
  void increaseStep ();
  void moveChopter (bool fuel);
  void checkColition ();
  void updateBlocks ();
  Chopter chopter;
  Map map;
public:
  Game();
  void onStep(bool buttonStatus);
  const Chopter & getChopter() const;
};
