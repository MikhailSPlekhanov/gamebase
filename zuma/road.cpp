#include "road.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

Path::Path(const std::vector<Coords>& dots) {
  for (int i = 0; i < dots.size(); i++) {
    (this->dots).push_back(dots[i]);
  }
  float x = dots[1].x - dots[0].x;
  float y = dots[1].y - dots[0].y;
  this->len = sqrt(x * x + y * y);
  this->dpos = 2 * RADIUS / len; //pos пробегает от 0 до 1, так что если поделить диаметр шара на длину пути, то получится разность в pos между соседними шарами
};

Coords Path::return_xy(const float pos) const {
  float x = this->dots[0].x + pos * (this->dots[1].x - this->dots[0].x);
  float y = this->dots[0].y + pos * (this->dots[1].y - this->dots[0].y);
  return Coords(x, y);
};

float Path::getLen() const {return this->len;};
float Path::getDpos() const {return this->dpos;}
Coords Path::getDotCoords(int i) const {return this->dots[i];}
int Path::getDotsSize() const {return this->dots.size();};


Road::Road(Path& path)
    : path{path} {
  this->endhole = EndHole(path.getDotCoords(this->path.getDotsSize())); //создали конечную дырку
  this->beginhole = EndHole(path.getDotCoords(0)); //создали конченую дырку
  Ball* ball;
  for (int j = 0; j < NUM_TO_GO; j++) { //заполнили очередь шаров на выезд шарами рандомного цвета
    ball = new Ball(path.getDotCoords(0), Colour(rand() % 4), 0);
    this->ballsToGo.push_back(std::make_unique<Ball>(ball));
  }
};

void Road::insertBall(int i, Ball& ball) { 
  this->balls.push_back(std::make_unique<Ball>(ball)); //вставили в конец очереди новый шар (FlyingBall который врезался)
  for (int j = this->balls.size() - 1; j > i; j--) { // с помощью swap двигаем его на свое место в очереди
    this->balls[j].swap(this->balls[j - 1]); 
  }
  float oldPos;
  for (int k = 0; k < i; k++) { // меняем pos всех шаров перед вставленным
    oldPos = this->balls[k]->get_position();
    this->balls[k]->set_position(oldPos + this->getPathDpos());
  }
};

void Road::move() {
    if ((this->lastBall()->get_position() < this->path.getDpos()) || (this->ballsToGo.empty()) ) { //проверили, что последний шар только что выехал на дорогу (то есть его толкают) или что больше некому выезжать
    this->lastBall()->set_position(this->lastBall()->get_position() + dt * ROAD_SPEED); //подвинули последний шар
    for (int i = this->balls.size() - 2; i > -1; i--) {
      if (this->balls[i]->get_position() < this->balls[i + 1]->get_position() + this->path.getDpos()) { // проверяем что предыдущий шар толкнул следующий
        this->balls[i]->set_position(this->balls[i]->get_position() + dt * ROAD_SPEED); //пододвигаем следующий
      }
    }
  }
}


bool Road::checkGameOver() {return (bool(this->endhole.get_coords().dist(this->firstBall()->get_coords()) < RADIUS)); }

void Road::addNewBall() {
    if (!(this->ballsToGo.empty())){
        if (this->balls.empty()) {
            this->balls.push_back(std::move(this->ballsToGo.back()));
            this->ballsToGo.pop_back();
        }
        else if (this->balls.back()->get_position() > this->path.getDpos()) {
            this->balls.push_back(std::move(this->ballsToGo.back()));
            this->ballsToGo.pop_back();
        }
    }
};

int Road::getBallsSize() const { return this->balls.size(); }
Coords Road::getBallCoords(int i) const {return this->balls[i]->get_coords(); }
void Road::setBallCoords(int i, const Coords coords) {this->balls[i]->set_coords(coords); }
float Road::getBallPosition(int i) const { return this->balls[i]->get_position(); }
void Road::setBallPosition(int i, const float x) {this->balls[i]->set_position(x); }
Colour Road::getBallColour(int i) const { return this->balls[i]->get_colour(); }
Ball* Road::lastBall() const { return this->balls[this->balls.size()].get(); }
Ball* Road::firstBall() const { return this->balls[0].get();}


float Road::getPathLen() const {
  return this->path.getLen();
};
float Road::getPathDpos() const {
  return this->path.getDpos();
}
Coords Road::return_xy(float pos) const {return this->path.return_xy(pos);}
;

