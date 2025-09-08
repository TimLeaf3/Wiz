
#include "../include/app.hpp"

// Access the App singleton
App *App::instance = 0;

App *App::ptr() {
  if (!instance) {
    instance = new App();
  }

  return instance;
}

// Init SDL
void App::init() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    throw std::runtime_error("error initializing SDL");
  }

  window = SDL_CreateWindow("Wiz", width, height, SDL_WINDOW_RESIZABLE);
  if (!window) {
    throw std::runtime_error("error creating SDL_Window");
  }

  renderer = SDL_CreateRenderer(window, NULL);
  if (!renderer) {
    throw std::runtime_error("error creating SDL_Renderer");
  }

  event = new SDL_Event();
  if (!event) {
    throw std::runtime_error("error creating SDL_Event");
  }

  running = true;
}

// Game Loop
void App::inputs() {
  while (SDL_PollEvent(event)) {
    switch (event->type) {
    case SDL_EVENT_QUIT:
      running = false;
      break;

    default:
      break;
    }
  }
}

void App::update() { //
  SDL_GetWindowSize(window, &width, &height);
}

void App::render() {
  SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
  SDL_RenderClear(renderer);

  //

  SDL_RenderPresent(renderer);
}

// Clean SDL
void App::clean() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();
}
