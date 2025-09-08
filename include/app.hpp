
#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <stdexcept>

#include "character.hpp"
#include "spell.hpp"
#include "utils.hpp"

class App {
private:
  App() = default;
  static App *instance;

  SDL_Window *window = 0;
  SDL_Renderer *renderer = 0;

  SDL_Event *event = 0;
  int width = 400, height = 400;

public:
  static App *ptr();

  bool running;

  void init();

  void inputs();
  void update();
  void render();

  void clean();
};
