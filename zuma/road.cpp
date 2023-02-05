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
  this->dpos = 2 * RADIUS / len; //pos ��������� �� 0 �� 1, ��� ��� ���� �������� ������� ���� �� ����� ����, �� ��������� �������� � pos ����� ��������� ������
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
}
Coords Path::getDotCoords(int i) {
  return this->dots[i];
}
int Path::getDotsSize() {
  return this->dots.size();
};


Road::Road(Path& path)
    : path{path} {
  this->endhole = EndHole(path.getDotCoords(this->path.getDotsSize())); //������� �������� �����
  this->beginhole = EndHole(path.getDotCoords(0)); //������� �������� �����
  Ball* ball;
  for (int j = 0; j < NUM_TO_GO; j++) { //��������� ������� ����� �� ����� ������ ���������� �����
    ball = new Ball(path.getDotCoords(0), 0, Colour(rand() % 4));
    this->ballsToGo.push_back(std::make_unique<Ball>(ball));
  }
};

void Road::insertBall(int i, Ball& ball) { 
  this->balls.push_back(std::make_unique<Ball>(ball)); //�������� � ����� ������� ����� ��� (FlyingBall ������� ��������)
  for (int j = this->balls.size(); j > i; j--) { // � ������� swap ������� ��� �� ���� ����� � �������
    this->balls[j].swap(this->balls[j - 1]); 
  }
  float oldPos;
  for (int k = 0; k < i; k++) { // ������ pos ���� ����� ����� �����������
    oldPos = this->balls[k]->get_position();
    this->balls[k]->set_position(oldPos + this->getPathDpos());
  }
};

void Road::move() {
  if (this->balls[this->balls.size()]->get_position() < 2 * RADIUS / this->path.getLen() ||
      this->ballsToGo.size() == 0) { //���������, ��� ��������� ��� ������ ��� ������ �� ������ (�� ���� ��� �������) ��� ��� ������ ������ ��������
    Ball* lastBall = this->balls[this->balls.size()].release(); //�������� ��������� �� ��������� ���
    lastBall->set_position(lastBall->get_position() + dt * ROAD_SPEED); //��������� ��������� ���
    for (int i = this->balls.size() - 1; i > -1; i--) {
      if (this->balls[i]->get_position() - 2 * RADIUS < this->balls[i + 1]->get_position()) { // ��������� ��� ���������� ��� ������� ���������
        this->balls[i]->set_position(this->balls[i]->get_position() + dt * ROAD_SPEED); //����������� ���������
      }
    }
  }
}


bool Road::checkGameOver() {
    return (bool(this->endhole.get_coords().dist(this->balls[0]->get_coords()) < RADIUS));
}
void Road::addNewBall() {
    if ((this->balls.back()->get_position() >
        this->path.getDpos()) && !(this->ballsToGo.empty()) ){
    this->balls.push_back(std::move(this->ballsToGo.back()));
    this->ballsToGo.pop_back();
    }
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
float Road::getPathDpos() const {
  return this->path.getDpos();
};

