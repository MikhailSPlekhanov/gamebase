#pragma once

#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Path { //класс пути: определяет форму дороги и обеспечивает взаимодействие с ней
 public:
  Path(const std::vector<Coords>& dots);
  Path(const Path&) = default;
  ~Path() = default;

  Coords return_xy(const float& pos) const; //возвращает координаты по позиции pos
  float getLen() const; // возвращает длину пути
  float getDpos() const; // возвращает dpos
  Coords getDotCoords(int i); // возвращает координаты iой опорной точки
  int getDotsSize(); //возвращает количество опорных точек

 private:
  std::vector<Coords> dots; //опорные точки по которым происходит построение траектории
  float len; //длина пути
  float dpos; //разность в pos между соседними шарами
};


class Road {//класс дороги: хранит массив шаров на ней, свою дырку и свою форму(Path). Также он может двигать шары и добавлять новые в начало пути
 public:
  Road(Path& path);
  Road(const Road&) = default;
  ~Road() = default;
  
  void insertBall(int i, Ball& ball);//вставляет указатель на шар ball на позицию i в вектор очереди balls
  void move();//двигает все шары
  bool checkGameOver(); //проверяет столкновение с дыркой
  void addNewBall(); //Вставляет в начало очереди новый шар если надо

  //работа с классом Ball
  int getBallsSize() const;//возвращает длину очереди (число шаров на дороге)

  void setBallCoords(int i, const Coords coords);//устанавливает координаты iго шара в очереди
  Coords getBallCoords(int i) const;//возвращает координаты iго шара в очереди
  void setBallPosition(int i, const float x);//устанавливает pos iго шара в очереди
  float getBallPosition(int i) const;//возвращает pos iго шара в очереди
  Colour getBallColour(int i) const;//возвращает цвет iго шара в очереди

  //работа с классом Path
  float getPathLen() const;//возвращает длину пути
  float getPathDpos() const;//возвращает разность в pos между соседними шарами

 
 private:
  std::vector<std::unique_ptr<Ball>> balls; //массив шаров на дороге. первым номером идет первый шар, в конец добавляются новые шары
  std::vector<std::unique_ptr<Ball>> ballsToGo; //массив шаров до выезда на дорогу. последний в массиве тот шар, который выезжает на дорогу
  Path path;
  EndHole endhole;
  EndHole beginhole;
};
