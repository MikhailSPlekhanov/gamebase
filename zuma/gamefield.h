#pragma once

#include "road.h"
#include "auxiliary.h"

class Frog {
 public:
  Frog();
  Frog(const float x, const float y);
  Frog(const Frog&) = default;
  ~Frog() = default;

  void set_angle(const Coords& coords);
  float get_angle(const Coords& coords);
  void shoot();
  void generate_next_colour();

 private:
  Coords coords;
  float angle, shoot_speed;
  Colour current_colour, next_colour;
};

class EndHole {
 public:
  EndHole(float x, float y, float ang);
  EndHole(const EndHole&) = default;
  ~EndHole() = default;
  Coords get_position();

 private:
  Coords coords;
  float angle;
};

class Gamefield {
 public:
  Gamefield(const std::vector<Road>& roads,
            const std::vector<EndHole> &endholes,
            Frog& frog);
  ~Gamefield() = default;

 private:
  std::vector<std::unique_ptr<FlyingBall>> flyingballs;
  std::vector<std::unique_ptr<Road>> roads;
  std::vector<std::unique_ptr<EndHole>> endholes;
  Frog frog;
};