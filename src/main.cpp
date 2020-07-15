#include <iostream>
#include "enemies.h"
#include "dodge.h"
#include "controller.h"
int main() {
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
 
  
  std::cout << "Game has terminated successfully!\n";

  return 0;
}
/*  Enemies   e1(kGridWidth,kGridHeight);
  Enemies   e2(kGridWidth,kGridHeight);
  Enemies   e3(kGridWidth,kGridHeight);
  std::cout << "e1.x="<<e1.x<<"	e1.y=" <<e1.y<<"\n";
  std::cout << "e2.x="<<e2.x<<"	e2.y=" <<e2.y<<"\n";
  std::cout << "e3.x="<<e3.x<<"	e3.y=" <<e3.y<<"\n";
  e1.Update();
  e2.Update();
  e3.Update();
  std::cout << "e1.x="<<e1.x<<"	e1.y=" <<e1.y<<"\n";
  std::cout << "e2.x="<<e2.x<<"	e2.y=" <<e2.y<<"\n";
  std::cout << "e3.x="<<e3.x<<"	e3.y=" <<e3.y<<"\n";
  
   Controller controller;
  bool running=1;
  Dodge   e1(kGridWidth,kGridHeight);
   Dodge::Direction previous= Dodge::Direction::kUp;
  std::cout << "e1.x="<<e1.x<<"	e1.y=" <<e1.y<<"\n";
  while(running)
  {
    controller.HandleInput(running, e1);
    if(e1.direction !=previous)
    {
      previous=e1.direction;
      std::cout << "e1.x="<<e1.x<<"	e1.y=" <<e1.y<<"\n";
    }
    
  }
  */