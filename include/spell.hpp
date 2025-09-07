
#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <string>

class spell {
private:
  std::string name;
  std::string description;

public:
  //

  std::string get_name() const { return name; }
  std::string get_description() const { return description; }
};
