#include "road.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


Path::Path(const std::vector<Coords>& dots){
    for (int i = 0; i < dots.size(); i++) {
      (this->dots).push_back(dots[i]);
    }
  }

Coords Path::return_xy(float pos) const {
  float x = this->dots[0].x + pos * (this->dots[1].x - this->dots[0].x);
  float y = this->dots[0].y + pos * (this->dots[1].y - this->dots[0].y);
  return Coords(x,y);
}

Road::Road(Path& path, std::vector<Ball>& balls) : path{path} {
  for (int i = 0; i < balls.size(); i++) {
    (this->balls).push_back(make_unique<Ball>(balls[i]));
  }
}

void Road::collide_check() {
  for (int i = 0; i < (this->balls).size(); i++) {
    if (balls[i]->get_coords().y < 800) {
      
    }
  }
}
