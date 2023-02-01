#pragma once

#include "road.h"
#include "auxiliary.h"


class Gamefield {//����� �������� ����: ������ ������� ������� �����, ������ ����� � ������ �����. �������� �� �� �������������� � ���������� ��������� ����
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