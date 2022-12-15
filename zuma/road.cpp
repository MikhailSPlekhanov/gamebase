#include "road.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;


Coords Path::return_xy(float pos) const {
  float x = this->dots[0].x + pos * (this->dots[1].x - this->dots[0].x);
  float y = this->dots[0].y + pos * (this->dots[1].y - this->dots[0].y);
  return Coords(x,y);
}



void Road::collide_check() {
  for (int i = 0; i < (this->balls).size(); i++) {
    if (balls[i]->get_coords().y < 800) {
      
    }
  }
}
