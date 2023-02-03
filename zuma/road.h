#pragma once

#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Path {
 public:
  Path(const std::vector<Coords>& dots);
  Path(const Path&) = default;
  ~Path() = default;
  Coords return_xy(const float& pos) const;
  float getLen() const;
  float getDpos() const;

 private:
  std::vector<Coords> dots;
  float len;
  float dpos;
};


class Road {//класс дороги хранит массив шаров на ней, свою дырку и свою форму(Path). Также он может двигать шары и добавлять новые в начало пути
 public:
  Road(Path& path, std::vector<Ball>& balls, EndHole& endhole);
  Road(const Road&) = default;
  ~Road() = default;
  
  void insertBall(int i, Ball* ball);//вставляет указатель на шар ball на позицию i в вектор очереди balls
  void move();//двигает все шары
  void gameOver(); //сбрасывает все шары в дырку
  void checkGameOver(); //проверяет столкновение с дыркой
  bool checkForNewBall(); //Вставляет в начало очереди новый шар если надо

  //работа с классом Ball
  int getBallsSize() const;//возвращает длину очереди (число шаров на дороге)

  void setBallCoords(int i, const Coords coords);//устанавливает координаты iго шара в очереди
  Coords getBallCoords(int i) const;//возвращает координаты iго шара в очереди
  void setBallPosition(int i, const float x);//устанавливает pos iго шара в очереди
  float getBallPosition(int i) const;//возвращает pos iго шара в очереди
  Colour getBallColour(int i) const;//возвращает цвет iго шара в очереди

  //работа с классом Path
  float getPathLen() const;//возвращает длину пути
  float getPathDeltaPos() const;//возвращает разность в pos между соседними шарами

 
 private:
  std::vector<std::unique_ptr<Ball>> balls; //первым номером идет первый шар, в конец добавляются новые шары.
  std::vector<std::unique_ptr<Ball>> ballsToGo; //массив шаров до выезда на дорогу.
  Path path;
  EndHole endhole;
};
