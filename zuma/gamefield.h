#pragma once

#include "road.h"
#include "auxiliary.h"


class Gamefield {//класс игрового поля: хранит массивы летящих шаров, массив дорог и массив дырок. Отвечает за их взаимодействие и управление процессом игры
 public:
  Gamefield(const std::vector<Road>& roads,
            const std::vector<EndHole> &endholes,
            Frog& frog);
  ~Gamefield() = default;
  void GamefieldRender();

 private:
  std::vector<std::unique_ptr<FlyingBall>> flyingballs;
  std::vector<std::unique_ptr<Road>> roads;
  std::vector<std::unique_ptr<EndHole>> endholes;
  Frog frog;
};