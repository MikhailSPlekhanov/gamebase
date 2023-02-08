#include "gamefield.h"
#include <cmath>

using namespace std;


Gamefield::Gamefield(const std::vector<Road>& roads, //получаем вектор дорог и лягушку
                     Frog& frog) {
  for (int i = 0; i < roads.size(); i++) {
    (this->roads).push_back(std::make_unique<Road> (roads[i]));
  }
}

void Gamefield::GamefieldRender() {
    
}

void Gamefield::insertCollisions() { // ищет столкновения летящих шаров с шарами на дорогах и если надо вставляет шары
  for (int iroad = 0; iroad < this->roads.size(); iroad++) { 
    for (int iball = 0; iball < this->roads[iroad]->getBallsSize(); iball++) { 
      for (int iFB = 0; iFB < this->flyingballs.size(); iFB++) { 
        if (this->roads[iroad]->getBallCoords(iball).dist(this->flyingballs[iFB]->get_coords()) < COLLIDE_DISTANCE) {
          Ball ball = Ball(this->roads[iroad]->getBallCoords(iball),this->flyingballs[iFB]->get_colour(), this->roads[iroad]->getBallPosition(iball));  // создали новый шар на основе летящего шара
          this->roads[iroad]->insertBall(iball, ball); //вставили шар в очередь
        }
      }
    }
  }
}

void Gamefield::popOverTripples() { //функция взрыва всех одинаковых цепочек
  for (int iroad = 0; iroad < this->roads.size(); iroad++) {
    for (int iball = 0; iball < this->roads[iroad]->getBallsSize(); iball++) {
      
    }
  }
}

void Gamefield::checkGameOver() { // проверяет столкновение с дыркой и говорит что игра
  bool flag = false;
  for (int i = 0; i < this->roads.size(); i++) {
    if (this->roads[i]->checkGameOver()) {
      this->game_over = true;
    }
  }
}

void Gamefield::move() { //подвинуть все шары и добавить новые
  for (int i = 0; i < this->roads.size(); i++) {
    this->roads[i]->move();
    this->roads[i]->addNewBall();
  }
  for (int j = 0; j < this->flyingballs.size(); j++) {
      this->flyingballs[j]->move();
  }
}

void Gamefield::updateCoords(){ //установить координаты всех шаров в соответствии с их позицией
    for (int iroad = 0; iroad < this->roads.size(); iroad++) {
        for (int iball = 0; iball < this->roads[iroad]->getBallsSize(); iball++) {
            this->roads[iroad]->setBallCoords(iball, this->roads[iroad]->return_xy(this->roads[iroad]->getBallPosition(iball)));
        }
    }
}

void Gamefield::updateFrog(Coords mouse)
{
    this->frog.set_angle(mouse);
}

void Gamefield::shoot()
{
    this->flyingballs.push_back(std::make_unique<FlyingBall>(*(this->frog.shoot())));
}

