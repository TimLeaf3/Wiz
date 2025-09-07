
#pragma once

struct stats {
  float hp = 0;
  float attack = 0;
  float defense = 0;
};

enum class spell_kind {
  abjuration,  // banishment, anti-magic
  alteration,  // buffs / debuffs, transmutation, levitation
  conjuration, // summoning creatures / weapons, teleportation
  destruction, // offensive spells (fire, ice, lightning, acid, ...)
  druidic,     // talking to / turning into animals
  divination,  // detect enemies, foresee events, scrying
  illusion,    // invisibility, fear, charm
  necromancy,  // raising undead, life drain, curses
  restoration, // heal wounds, cure poison, protection
  runic,       // glyph traps, delayed effect
  telepathy    // mind contol, mind reading
};

enum class spell_type {
  air,    // ground control
  cursed, // necromancy, curses
  earth,  // attacks, defense
  fire,   // attacks, cooking, light
  ice,    // slowness, walk on water
  plant,  // vines, growing crops
  soul,   // capturing souls
  water,  // attacks, healing
  weather // change the weather
};