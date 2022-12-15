#include "gamefield.h"
#include <cmath>

using namespace std;



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
Frog::~Frog() = default;

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


Gamefield::Gamefield(const std::vector<Road>& roads,
                     const std::vector<EndHole>& endholes,
                     Frog& frog) {
  for (int i = 0; i < roads.size(); i++) {
    (this->roads).push_back(make_unique<Road> (roads[i]));
    (this->endholes).push_back(make_unique<EndHole>(endholes[i]));
  }
}

Gamefield::~Gamefield() = default;
