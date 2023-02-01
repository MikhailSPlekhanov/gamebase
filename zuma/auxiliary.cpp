#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

Coords::Coords() {
  x = 0;
  y = 0;
}
Coords::Coords(float x, float y) : x{x}, y{y} {}

void Coords::inc(float dx, float dy) {
  this->x += dx;
  this->y += dy;
}

/* bool Coords::operator==(const Coords& o) const {
  return x == o.x && y == o.y;
}*/

Ball::Ball()
    : coords{Coords(0, 0)},
      pos{0},
      speed{0.1},
      last{true},
      push{true},
      colour{Colour(rand() % 4)} {}
Ball::Ball(float x, float y, Colour col) : coords{Coords(x, y)}, colour{col} {};

Coords Ball::get_coords() const {
  return this->coords;
}

void Ball::set_coords(float x, float y) {
  this->coords = Coords(x, y);
}

void Ball::set_position(const float pos) {
  this->pos = pos;
};

float Ball::get_position() const {
  return this->pos;
}
Colour Ball::get_colour() const {
  return this->colour;
};

FlyingBall::FlyingBall(const float x,
                       const float y,
                       const float vx,
                       const float vy,
                       Colour col)
    : coords{Coords(x, y)}, vx{vx}, vy{vy}, colour{col} {};
FlyingBall::~FlyingBall() = default;

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

Frog::Frog(const float x, const float y)
    : coords{Coords(x, y)},
      angle{0},
      shoot_speed{10},
      current_colour{Colour(rand() % 4)},
      next_colour{Colour(rand() % 4)} {}

void Frog::set_angle(const Coords& coords) {
  this->angle = this->get_angle(coords);
}

float Frog::get_angle(const Coords& coords) {
  return atan2((coords.y - this->coords.y), (coords.x - this->coords.x));
}

void Frog::shoot() {
  float vx = this->shoot_speed * cos(this->angle);
  float vy = this->shoot_speed * sin(this->angle);
  FlyingBall* ball = new FlyingBall(this->coords.x, this->coords.y, vx, vy,
                                    this->current_colour);
}

void Frog::generate_next_colour() {
  this->current_colour = this->next_colour;
  this->next_colour = Colour(rand() % 4);
}

EndHole::EndHole(float x, float y, float ang)
    : coords{Coords(x, y)}, angle{ang} {};

Coords EndHole::get_position() {
  return this->coords;
}
