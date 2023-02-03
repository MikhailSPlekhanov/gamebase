#pragma once
//тут лежат enum цветов, классы координат, шара, летающего шара, л€гушки и дырки.
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const float COLLIDE_DISTANCE = 1;
const float ROAD_SPEED = 1;
const float RADIUS = 1;
const float dt = 1;

enum Colour { red = 0, green, blue, yellow };

struct Coords { //структура координат (вектор). ћожно прибавл€ть координаты (inc(dx, dy)).
  Coords();
  Coords(float x, float y);
  Coords(const Coords&) = default;
  ~Coords() = default;
  
  void inc(float dx, float dy);
  float mod() const;
  //Coords operator + (const Coords& left, const Coords& right) const;
  float dist(const Coords& two) const;

  float x, y;
};

class Ball {
 public:
  Ball();
  Ball(Coords coords, Colour col);
  Ball(const Ball&) = default;
  ~Ball() = default;

  Coords get_coords() const;
  void set_coords(const Coords coords);
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
  FlyingBall();
  FlyingBall(Coords coords, const float vx, const float vy, Colour col);
  FlyingBall(const FlyingBall&) = default;
  ~FlyingBall() = default;

  Coords get_coords() const;
  void move();
  bool collide(FlyingBall& FB1, FlyingBall& FB2) const;
  Colour get_colour() const;

 private:
  Coords coords;
  float vx, vy;
  Colour colour;
};

class Frog {
 public:
  Frog();
  Frog(Coords& coords);
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

class EndHole {//класс дырки. Ќепон€тно вообще, нужен ли он. Ќо на вс€кий случай создан (дл€ красоты). ћожет возвращать свои координаты.
 public:
  EndHole(Coords& coords);
  EndHole(const EndHole&) = default;
  ~EndHole() = default;
  Coords get_coords();

 private:
  Coords coords;
};