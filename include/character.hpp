
#pragma once

#include "utils.hpp"
#include <string>

class character {
protected:
  character(std::string name = "Unknown", int lvl = 1)
      : name(name), level(lvl) {}

  std::string name;
  bool alive = true;

  void level_up();

  int get_level() const;
  const stats &get_stats() const;

  void add_health(float amount);
  void lose_health(float amount);

  void add_mana(float amount);
  void lose_mana(float amount);

private:
  int level;
  stats core_stats;

  float max_mana = 50.0;
  float max_health = 50.0;

  void resuscitate(int percent);
  void die();

public:
  inline virtual void inputs() = 0;
  inline virtual void update() = 0;
  inline virtual void render() = 0;
};

inline void character::level_up() { level++; }

inline int character::get_level() const { return level; }
inline const stats &character::get_stats() const { return core_stats; }

/// @brief  Adds health to the character
/// @param amount the amount of health to add
inline void character::add_health(float amount) {
  if (amount <= 0) {
    return;
  }

  else if (core_stats.health + amount > max_health) {
    core_stats.health = max_health;
  }

  else {
    core_stats.health += amount;
  }
}

/// @brief Removes health from the character
/// @param amount the amount of health to subtract
inline void character::lose_health(float amount) {
  if (amount <= 0) {
    return;
  }

  else if (core_stats.health - amount < 0) {
    core_stats.health = 0;
    die();
  }

  else {
    core_stats.health -= amount;
  }
}

/// @brief  Adds mana to the character
/// @param amount the amount of mana to add
inline void character::add_mana(float amount) {
  if (amount <= 0)
    return;

  else if (core_stats.mana + amount > max_mana)
    core_stats.mana = max_mana;

  else
    core_stats.mana += amount;
}

/// @brief Removes mana from the character
/// @param amount the amount of mana to subtract
inline void character::lose_mana(float amount) {
  if (amount <= 0)
    return;

  else if (core_stats.mana - amount < 0)
    core_stats.mana = 0;

  else
    core_stats.mana -= amount;
}

/// @brief sets the character's state to "not alive"
inline void character::die() { alive = false; }

/// @brief sets the character's state to "alive" and restores some health
void character::resuscitate(int percent) {
  if (percent < 1) {
    core_stats.health = 1;
  } else {
    add_health(max_health * percent / 100);
  }

  alive = true;
}
