#ifndef DODGE_H
#define DODGE_H

#include <vector>
#include "SDL.h"

class Dodge {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight ,KHold};

  Dodge(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        _x(grid_width / 2),
        _y(grid_height / 2) {}

  void Update();


  bool DodgeCell(int x, int y);

  Direction direction = Direction::KHold;

  float speed{.1};

  bool alive{true};
  float _x;
  float _y;


 private:

  int grid_width;
  int grid_height;
};

#endif