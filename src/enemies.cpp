#include "enemies.h"
#include <cmath>
#include <iostream>

void Enemies::Update() {

      y += speed;
}


// Inefficient method to check if cell is occupied by snake.
bool Enemies::DodgeCell(int x, int y) {
  if (x == static_cast<int>(x) && y == static_cast<int>(y)) {
    return true;
  }
  return false;
}