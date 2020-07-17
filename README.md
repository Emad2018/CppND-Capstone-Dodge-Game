# CPPND: Capstone Dodge Repo

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="dodge.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application starting with this repo, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Dodge`.

## Game
1. Start the game 
2. Use the Arrow Key 
3. Avoid the Enemies 
4. You can restart the game when you Die by answer the question "Play again?press y"

## Game Structure 
1. main
2. Game       ==> Game logic  
3. Controller ==> Take the user Input
4. Renderer   ==> Display the Dodge and the Enemies 
5. Dodge      ==> the base class for the Dodge object 
6. Enemie     ==> the base class for the Falling Enemie 

## Rubric points
1. Loops, Functions, I/O
   * The project demonstrates an understanding of C++ functions and control structures :
      main.cpp/game.cpp/render.cpp
   * The project reads data from a file and process the data, or the program writes data to a file:
      main.cpp line 21,44
   * The project accepts user input and processes the input:
      game.cpp line 57
	  
2. Object Oriented Programming:
   * The project uses Object Oriented Programming techniques:
       X.h ,X.cpp
   * Classes use appropriate access specifiers for class members:
	   X.h
   * Class constructors utilize member initialization lists:
       X.h
   * Classes abstract implementation details from their interfaces:
       X.h
   * Classes encapsulate behavior:
       X.h
   * Classes follow an appropriate inheritance hierarchy:
       X.h
   * Overloaded functions allow the same function to operate on different parameters:
       enemie.h line 12,13
   * Derived class functions override virtual base class functions:
      NONE
   * Templates generalize functions in the project:
      main.cpp
   
3. Memory Management:
   * The project makes use of references in function declarations: 
       dodge.h/enemie.h
   * The project uses destructors appropriately:
       renderer.cpp
   * The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate:
      renderer.cpp
   * The project follows the Rule of 5:
       NONE
   * The project uses move semantics to move data, instead of copying it, where possible:
      game.cpp Game::Game
   * The project uses smart pointers instead of raw pointers:
      game.h line 21 _enemies
   

   
