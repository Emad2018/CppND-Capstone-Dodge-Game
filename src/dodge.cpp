#include "dodge.h"
#include <cmath>
#include <iostream>

void Dodge::Update() {
  switch (direction) {
    case Direction::kUp:
      _y -= speed;
      break;

    case Direction::kDown:
      _y += speed;
      break;

    case Direction::kLeft:
      _x -= speed;
      break;

    case Direction::kRight:
      _x += speed;
      break;
    default:
        break;
  }

  // Wrap the Dodge around to the beginning if going off of the screen.
  _x = fmod(_x + grid_width, grid_width);
  _y = fmod(_y + grid_height, grid_height);
}



bool Dodge::DodgeCell(int x, int y) {
  if (static_cast<int>(_x) == static_cast<int>(x) && static_cast<int>(_y) == static_cast<int>(y)) {
    
    return true;
  }
  return false;
}