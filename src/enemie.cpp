#include "enemie.h"
#include <cmath>
#include <iostream>

Enemie::Enemie(int grid_width, int grid_height)      : grid_width(grid_width),
                                                         grid_height(grid_height),
        												 engine(dev()),
     													 random_w(0, static_cast<int>(grid_width))
{

        x = random_w(engine);

}
void Enemie::Update() {

      y += speed;
      y = fmod(y + grid_height, grid_height);
}

