#ifndef DODGE_H
#define DODGE_H

#include <vector>
#include "SDL.h"

class Enemies {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Enemies(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        x(grid_width / 2),
        y(grid_height / 2) {}

  void Update();


  bool EnemiesCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};

  bool alive{true};
  float x;
  float y;


 private:

  int grid_width;
  int grid_height;
};

#endif