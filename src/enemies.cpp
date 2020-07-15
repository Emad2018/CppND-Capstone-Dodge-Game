#include "enemies.h"
#include <cmath>
#include <iostream>

Enemies::Enemies(int grid_width, int grid_height)      : grid_width(grid_width),
                                                         grid_height(grid_height),
        												 engine(dev()),
     													 random_w(0, static_cast<int>(grid_width))
{

        x = random_w(engine);

}
void Enemies::Update() {

      y += speed;
}

