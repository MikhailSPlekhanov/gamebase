#pragma once
// тут лежит класс пути и дороги
#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Path {//пока самый простой вид пути: хранит две точки и строит прямую линию между ними (return_xy)
  public:
    Path(const std::vector<Coords>& dots); //самый простой контруктор: сохраняем две точки для 
    Path(const Path&) = default;
    ~Path() = default;
    Coords return_xy(float pos) const;

  private:
  std::vector<Coords> dots;
};

class Road {//класс дороги хранит массив шаров на ней и свою форму(Path). Также он может двигать шары и добавлять новые в начало пути
 public:
  Road(Path& path, std::vector<Ball>& balls);
  Road(const Road&) = default;
  ~Road() = default;
  void collide_check();
  void move();//двигаем все шары
  void gameOver(); //сбрасываем все шары в дырку
  void checkGameOver(); //проверяем столкновение с дыркой
  bool checkIfNewBallNeeded(); //проверяем если нужен новый шар в начало пути

 private:
  std::vector<std::unique_ptr<Ball>> balls;
  Path path;
};
