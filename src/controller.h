#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "dodge.h"

class Controller
{
public:
  void HandleInput(bool &running, Dodge &dodge) const;
};

#endif