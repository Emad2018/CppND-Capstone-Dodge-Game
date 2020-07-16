#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
#include <sstream>
#include <string>

int main() {
  // set the const values 
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{500 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{10};
  constexpr std::size_t kGridHeight{10};
  std::string line;
  int value;
  std::ofstream myfile;
  std::ifstream filestream("../src/score.txt");                   //read the highest score from a file  
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      linestream >> value;      
      std::cout<<"Highest score: " <<value<<"\n";
    }
  }

  filestream.close();
  bool _play{true};                                                         
while(_play)                                                                   
{
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame,_play);                          // start the game 
   std::cout << "Your Score: " << game.GetScore() << "\n";                    //print the score if the 

  if(value<game.GetScore())                                                   // check if we have new highest score
  {
    myfile.open("../src/score.txt");
    std::cout << "New Max Score: " << game.GetScore() << "\n";        
    myfile << game.GetScore();                                               // write the highest score to the file
    myfile.close();
  }
}
  std::cout << "Game has terminated successfully!\n";
 
  return 0;
}