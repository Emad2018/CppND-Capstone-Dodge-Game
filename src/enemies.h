#ifndef ENEMIES_H
#define ENEMIES_H

#include <random>
#include <vector>
#include "SDL.h"

class Enemies {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Enemies(int grid_width, int grid_height);
  void Update();
  
  float speed{0.1f};
  float x;
  float y{0};


 private:
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  int grid_width;
  int grid_height;
   Direction direction = Direction::kDown;
};

#endif