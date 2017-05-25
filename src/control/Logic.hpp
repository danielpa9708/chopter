#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <SDL2/SDL.h>
#include "Controller.hpp"

class Controller;

class Logic {
  SDL_Window * window;
  SDL_Surface * screenSurface;
  void runGameController();
public:
  enum Signal { PlayGame };
  void init();
  void run();
  void quit();
  void manage(Controller &controller);
  void sign(Signal signal);
  SDL_Window * getWindow() { return window; }
  SDL_Surface * getScreenSurface() { return screenSurface; }
};

#endif
