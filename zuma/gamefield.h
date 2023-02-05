#pragma once

#include "road.h"
#include "auxiliary.h"


class Gamefield {//����� �������� ����: ������ ������� ������� �����, ������ ����� � ������ �����. �������� �� �� �������������� � ���������� ��������� ����
 public:
  Gamefield(const std::vector<Road>& roads,
            Frog& frog);
  Gamefield(const Gamefield&) = default;
  ~Gamefield() = default;
  void GamefieldRender();
  void insertCollisions();
  void popOverTripples();
  void checkGameOver();
  void move();

 private:
  std::vector<std::unique_ptr<FlyingBall>> flyingballs;
  std::vector<std::unique_ptr<Road>> roads;
  Frog frog;
  bool game_over = false;
};