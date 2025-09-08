
#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <functional>
#include <string>

#include "character.hpp"

class spell {
private:
  std::string name;
  std::string description;

  std::function<void(character &c)> effect;

public:
  //

  std::string get_name() const { return name; }
  std::string get_description() const { return description; }
};
