#include "gamefield.h"
#include <cmath>

using namespace std;


Gamefield::Gamefield(const std::vector<Road>& roads, //получаем два вектора: дороги и 
                     const std::vector<EndHole>& endholes,
                     Frog& frog) {
  for (int i = 0; i < roads.size(); i++) {
    (this->roads).push_back(make_unique<Road> (roads[i]));
    (this->endholes).push_back(make_unique<EndHole>(endholes[i]));
  }
}

void Gamefield::GamefieldRender() {

}

