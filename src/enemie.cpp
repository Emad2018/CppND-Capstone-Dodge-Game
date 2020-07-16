#include "enemie.h"
#include <cmath>
#include <iostream>

float Enemie::speed = .1;
Enemie::Enemie(int grid_width, int grid_height) : grid_width(grid_width),
                                                  grid_height(grid_height),
                                                  engine(dev()),
                                                  random_w(0, static_cast<int>(grid_width))
{

      x = random_w(engine); // start from random location in top of the sceern
}
void Enemie::Update()
{

      y += speed; // move down  in the sceen
}
void Enemie::Update(float input_speed)
{
      speed += input_speed;
      y += speed; // move down  in the sceen
}