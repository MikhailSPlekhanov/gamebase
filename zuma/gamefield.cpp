#include "gamefield.h"
#include <cmath>

using namespace std;


Gamefield::Gamefield(const std::vector<Road>& roads, //получаем вектор дорог и лягушку
                     Frog& frog) {
  for (int i = 0; i < roads.size(); i++) {
    (this->roads).push_back(make_unique<Road> (roads[i]));
  }
}

void Gamefield::GamefieldRender() {
    
}

void Gamefield::collide_check() {
  for (int i = 0; i < this->roads.size(); i++) {
    for (int j = 0; j < this->roads[i]->getBallsSize(); j++) {
      for (int k = 0; k < this->flyingballs.size(); k++) {
        if (this->roads[i]->getBallCoords(j).dist(this->flyingballs[k]->get_coords()) < COLLIDE_DISTANCE) {
          for (int q = 0; q < j; q++) {
            Ball* ball = new Ball(this->flyingballs[k]->get_coords(),
                      this->flyingballs[k]->get_colour());//создали новый шар на основе летящего шара
            this->roads[i].insertBall(k, ball);//вставили 
            this->roads[i]->setBallPosition( q, roads[i]->getBallPosition(q) + roads[i]->getPathDpos());
          }
        }
      }
    }
  }
}
