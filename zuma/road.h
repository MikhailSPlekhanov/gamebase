#pragma once

#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Path {
  public:
    Path(const std::vector<Coords>& dots);
   ~Path() = default;
    Coords return_xy(float pos) const;

  private:
  std::vector<Coords> dots = {Coords(600, 800), Coords(600, 0)};
};

class Road {
 public:
  Road();
  Road(const Road&) = default;
  ~Road() = default;
  void collide_check();

 private:
  std::vector<std::unique_ptr<Ball>> balls;
  Path path;
};