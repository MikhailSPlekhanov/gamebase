#pragma once

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const float COLLIDE_DISTANCE = 1;
const float ROAD_SPEED = 1;
const float RADIUS = 0.5;
const float dt = 1;

enum Colour { red = 0, green, blue, yellow };

struct Coords {
  Coords();
  Coords(float x, float y);
  float x, y;
  bool operator==(const Coords& o) const { return x == o.x && y == o.y; };
  void inc(float dx, float dy);
};

class Ball {
 public:
  Ball();
  Ball(float x, float y, Colour col);
  ~Ball() = default;
  Coords get_coords() const;
  void set_coords(float x, float y);
  void set_position(const float x);
  float get_position() const;
  Colour get_colour() const;

 private:
  Coords coords;
  float pos, speed = 0.1;
  bool last, push;
  Colour colour;
};

class FlyingBall {
 public:
  FlyingBall(const float x,
             const float y,
             const float vx,
             const float vy,
             Colour col);
  ~FlyingBall();
  void move();
  bool collide(FlyingBall& FB1, FlyingBall& FB2) const;
  Colour get_colour() const;

 private:
  Coords coords;
  float vx, vy;
  Colour colour;
};