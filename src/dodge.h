#ifndef DODGE_H
#define DODGE_H

#include <vector>
#include "SDL.h"

class Dodge {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Dodge(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        x(grid_width / 2),
        y(grid_height / 2) {}

  void Update();


  bool DodgeCell(int x, int y);

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