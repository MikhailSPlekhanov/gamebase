#pragma once
//тут лежат enum цветов, классы координат, шара, летающего шара, лягушки и дырки.
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const float COLLIDE_DISTANCE = 1; //расстояние, на котором шары сталкиваются
float ROAD_SPEED = 1; //скорость движени шаров по дороге
const float RADIUS = 1; //радиус шара
const float dt = 1; //шаг по времени
const int NUM_TO_GO = 10; //число шаров которые выедут после начала уровня

enum Colour { red = 0, green, blue, yellow }; // возможные цвета шаров

struct Coords { //структура координат (вектор). Можно прибавлять координаты (inc(dx, dy)).
  Coords();
  Coords(float x, float y);
  Coords(const Coords&) = default;
  ~Coords() = default;
  
  void inc(float dx, float dy); // увеличивает координаты на вектор (dx, dy)
  float mod() const; // возвращает длину вектора (x,y)
  //Coords operator + (const Coords& left, const Coords& right) const;
  float dist(const Coords& two) const; // возвращает расстояние от объекта до своего аргумента

  float x, y;
};

class Ball { //класс шаров, едущих по дороге
 public:
  Ball();
  Ball(Coords coords, Colour col);
  Ball(Coords coords, float pos, Colour col);
  Ball(const Ball&) = default;
  ~Ball() = default;

  Coords get_coords() const;
  void set_coords(const Coords coords);
  void set_position(const float x);
  float get_position() const;
  Colour get_colour() const;
  void setPush(bool flag);
  bool getPush();

 private:
  Coords coords;
  float pos, speed = 0.1; 
  bool last, push;
  Colour colour;
};

class FlyingBall { //класс летящих шаров
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

class Frog { // класс лягушки
 public:
  Frog();
  Frog(Coords& coords);
  Frog(const Frog&) = default;
  ~Frog() = default;

  Coords get_coords();
  void set_angle(const Coords& coords);//устанавливает угол поворота
  float get_angle(const Coords& coords);//возвращает свой угол поворота (зачем??)
  FlyingBall* shoot(); //создает новый летящий шар и возвращает указатель на него
  void generate_next_colour(); //задает цвета следующего шара для выстрела. надо будет подправить так, чтобы подбирала цвет по уже имеющимся в очереди

 private:
  Coords coords; //координаты лягушки
  float angle, shoot_speed; //угол поворота лягушки, скорость выстрела
  Colour current_colour, next_colour; //цвет выстрела и следующего за ним шара
};

class EndHole {//класс дырки. Непонятно вообще, нужен ли он. Но на всякий случай создан (для красоты). Может возвращать свои координаты.
 public:
  EndHole();
  EndHole(Coords& coords);
  EndHole(const EndHole&) = default;
  ~EndHole() = default;
  Coords get_coords();
  void set_coords(Coords& coords);

 private:
  Coords coords;
};