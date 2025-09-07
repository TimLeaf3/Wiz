
#include "../include/player.hpp"

player::player() {
  stats.hp = 50;
  stats.attack = 10;
  stats.defense = 10;
}

// instance
player *player::instance = 0;

player *player::ptr() {
  if (!instance) {
    instance = new player();
  }

  return instance;
}
