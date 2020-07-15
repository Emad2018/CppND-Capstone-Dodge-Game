#include "dodge.h"
#include <cmath>
#include <iostream>

void Dodge::Update() {
  switch (direction) {
    case Direction::kUp:
      y -= speed;
      break;

    case Direction::kDown:
      y += speed;
      break;

    case Direction::kLeft:
      x -= speed;
      break;

    case Direction::kRight:
      x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  x = fmod(x + grid_width, grid_width);
  y = fmod(y + grid_height, grid_height);
}


// Inefficient method to check if cell is occupied by snake.
bool Dodge::DodgeCell(int x, int y) {
  if (x == static_cast<int>(x) && y == static_cast<int>(y)) {
    return true;
  }
  return false;
}