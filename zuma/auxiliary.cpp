#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

Coords::Coords() {
  (this->x) = 0;
  (this->y) = 0;
}

Coords::Coords(float x, float y) : x{x}, y{y} {}

void Coords::inc(float dx, float dy) {
  (this->x) += dx;
  (this->y) += dy;
}

float Coords::mod() const {
  return sqrt((this->x) * (this->x) + (this->y) * (this->y));
}

float Coords::dist(const Coords& two) const {
  float x = two.x - this->x;
  float y = two.y - this->y;
  return sqrt(x * x + y * y);
}

Ball::Ball()
    : coords{Coords(0, 0)},
      colour{Colour(rand() % 4)},
      pos{0},
      speed{ROAD_SPEED},
      last{true},
      push{true} {};

Ball::Ball(Coords coords, Colour col)
    : coords{coords},
      colour{col},
      pos{0},
      speed{ROAD_SPEED},
      last{true},
      push{true} {}

Ball::Ball(Coords coords, float pos, Colour col)
    : coords{coords}, pos{pos}, colour {col} {};

Coords Ball::get_coords() const {
  return this->coords;
}

void Ball::set_coords(const Coords coords) {
  this->coords = coords;
}

void Ball::set_position(const float pos) {
  this->pos = pos;
};

float Ball::get_position() const {
  return this->pos;
}

Colour Ball::get_colour() const {
  return this->colour;
}

void Ball::setPush(bool flag) {
  this->push = flag;
}

bool Ball::getPush() {
  return this->push;
}



FlyingBall::FlyingBall()
    : coords{Coords(0, 0)}, vx{0}, vy{0}, colour{Colour(rand() % 4)} {}

FlyingBall::FlyingBall(Coords coords,
                       const float vx,
                       const float vy,
                       Colour col)
    : coords{coords}, vx{vx}, vy{vy}, colour{col} {};

Coords FlyingBall::get_coords() const {
  return this->coords;
}

void FlyingBall::move() {
  this->coords.inc(this->vx * dt, this->vy * dt);
};

bool FlyingBall::collide(FlyingBall& FB1, FlyingBall& FB2) const {
  float dx = FB1.coords.x - FB2.coords.x;
  float dy = FB1.coords.y - FB2.coords.y;
  return bool(dx * dx + dy * dy < COLLIDE_DISTANCE * COLLIDE_DISTANCE);
}

Colour FlyingBall::get_colour() const {
  return this->colour;
};



Frog::Frog()
    : coords{Coords(0, 0)},
      angle{0},
      shoot_speed{0.1},
      current_colour{Colour(rand() % 4)},
      next_colour{Colour(rand() % 4)} {}

Frog::Frog(Coords& coords)
    : coords{coords},
      angle{0},
      shoot_speed{10},
      current_colour{Colour(rand() % 4)},
      next_colour{Colour(rand() % 4)} {}

Coords Frog::get_coords() {
  return this->coords;
}

void Frog::set_angle(const Coords& coords) {
  this->angle = this->get_angle(coords);
}

float Frog::get_angle(const Coords& coords) {
  return atan2((coords.y - this->coords.y), (coords.x - this->coords.x));
}

FlyingBall* Frog::shoot() {
  float vx = this->shoot_speed * cos(this->angle);
  float vy = this->shoot_speed * sin(this->angle);
  FlyingBall* FB = new FlyingBall(this->coords, vx, vy,
                                    this->current_colour);
  return FB; 
}

void Frog::generate_next_colour() {
  this->current_colour = this->next_colour;
  this->next_colour = Colour(rand() % 4);
}



EndHole::EndHole() {
  this->coords = Coords(0, 0);
}

EndHole::EndHole(Coords& coords)
    : coords{coords} {};

Coords EndHole::get_coords() {
  return (this->coords);
}

void EndHole::set_coords(Coords& coords) {
  this->coords = coords;
}
