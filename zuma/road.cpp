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

Coords Path::return_xy(const float& pos) const {
  float x = this->dots[0].x + pos * (this->dots[1].x - this->dots[0].x);
  float y = this->dots[0].y + pos * (this->dots[1].y - this->dots[0].y);
  return Coords(x, y);
};

float Path::getLen() const {
  return this->len;
};

float Path::getDpos() const {
  return this->dpos;
};


Road::Road(Path& path, std::vector<Ball>& balls, EndHole& endhole)
    : path{path}, endhole{endhole} {
  for (int i = 0; i < balls.size(); i++) {
    (this->balls).push_back(make_unique<Ball>(balls[i]));
  }
};

void Road::insertBall(int i, Ball* ball) {
  this->balls.insert(i, make_unique<Ball>(ball));
};

void Road::move() {

};

int Road::getBallsSize() const {
  return this->balls.size();
}

Coords Road::getBallCoords(int i) const {
  return this->balls[i]->get_coords();
}

void Road::setBallCoords(int i, const Coords coords) {
  this->balls[i]->set_coords(coords);
};

float Road::getBallPosition(int i) const {
  return this->balls[i]->get_position();
};

void Road::setBallPosition(int i, const float x) {
  this->balls[i]->set_position(x);
};

Colour Road::getBallColour(int i) const {
  return this->balls[i]->get_colour();
};




float Road::getPathLen() const {
  return this->path.getLen();
};

float Road::getPathDeltaPos() const {
  return this->path.getDpos();
};

