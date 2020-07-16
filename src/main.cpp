#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
#include <sstream>
#include <string>

template <typename T>
void print_score(string message, T score)
{
  std::cout << message << score << std::endl;
}
int main()
{
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
  std::ifstream filestream("../src/score.txt"); //read the highest score from a file
  if (filestream.is_open())
  {
    while (std::getline(filestream, line))
    {
      std::istringstream linestream(line);
      linestream >> value;
      print_score<int>("Highest score: ", value);
    }
  }

  filestream.close();
  bool _play{true};
  while (_play)
  {
    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame, _play); // start the game
    print_score<int>("Your Score: ", game.GetScore());  //print the score if the

    if (value < game.GetScore()) // check if we have new highest score
    {
      myfile.open("../src/score.txt");
      print_score<int>("New Max Score: ", game.GetScore());
      myfile << game.GetScore(); // write the highest score to the file
      myfile.close();
    }
  }
  std::cout << "Game has terminated successfully!\n";

  return 0;
}