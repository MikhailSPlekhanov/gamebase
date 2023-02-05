#include "gamefield.h"
#include <cmath>

using namespace std;


Gamefield::Gamefield(const std::vector<Road>& roads, //�������� ������ ����� � �������
                     Frog& frog) {
  for (int i = 0; i < roads.size(); i++) {
    (this->roads).push_back(std::make_unique<Road> (roads[i]));
  }
}

void Gamefield::GamefieldRender() {
    
}

void Gamefield::insertCollisions() { // ���� ������������ ������� ����� � ������ �� ������� � ���� ���� ��������� ����
  for (int iroad = 0; iroad < this->roads.size(); iroad++) { 
    for (int iball = 0; iball < this->roads[iroad]->getBallsSize(); iball++) { 
      for (int iFB = 0; iFB < this->flyingballs.size(); iFB++) { 
        if (this->roads[iroad]->getBallCoords(iball).dist(this->flyingballs[iFB]->get_coords()) < COLLIDE_DISTANCE) {
          Ball ball = Ball(this->roads[iroad]->getBallCoords(iball), this->roads[iroad]->getBallPosition(iball), this->flyingballs[iFB]->get_colour());  // ������� ����� ��� �� ������ �������� ����
          this->roads[iroad]->insertBall(iball, ball); //�������� ��� � �������
        }
      }
    }
  }
}

void Gamefield::popOverTripples() {
  for (int iroad = 0; iroad < this->roads.size(); iroad++) {
    for (int iball = 0; iball < this->roads[iroad]->getBallsSize(); iball++) {
      
    }
  }
}

void Gamefield::checkGameOver() {
  bool flag = false;
  for (int i = 0; i < this->roads.size(); i++) {
    if (this->roads[i]->checkGameOver()) {
      this->game_over = true;
    }
  }
}

void Gamefield::move() {
  for (int i = 0; i < this->roads.size(); i++) {
    this->roads[i]->move();
  }
}
