#ifndef ENEMIE_H
#define ENEMIE_H

#include <random>
#include <vector>
#include "SDL.h"

class Enemie
{
public:
   Enemie(int grid_width, int grid_height);
   void Update();
   void Update(float input_speed);

   static float speed;
   float x;
   float y{0};

private:
   std::random_device dev;
   std::mt19937 engine;
   std::uniform_int_distribution<int> random_w;
   int grid_width;
   int grid_height;
};

#endif