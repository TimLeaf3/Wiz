
#pragma once

#include "utils.hpp"
#include <string>

class player {
private:
  player();
  static player *instance;

  stats stats{100, 10, 10};

public:
  static player *ptr();
};
