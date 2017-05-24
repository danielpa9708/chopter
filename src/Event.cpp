#include <SDL2/SDL_events.h>
#include <SDL2/SDL_timer.h>
#include "Event.hpp"

Event::Event() {
  quit = false;
  timeout = 1000/30;
  resetTime();
}

bool Event::waitForStepTime() {
  hasPressedKey = false;
  while(checkEvents()) {}
  return !quit;
}

bool Event::checkForButtonDown() const {
  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
  return currentKeyStates[SDL_SCANCODE_UP] || hasPressedKey;
}

bool Event::checkEvents() {
  SDL_Event event;
  while (!quit && SDL_PollEvent(&event) != 0) {
    switch (event.type) {
    case SDL_QUIT:
      quit = true;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_UP) {
        hasPressedKey = true;
      }
      break;
    }
  }
  if (isTime()) {
    resetTime();
    return false;
  }
  return !quit;
}

bool Event::isTime() {
  return prevTime + timeout <= SDL_GetTicks();
}

void Event::resetTime() {
  prevTime = SDL_GetTicks();
}