#pragma once
// ��� ����� ����� ���� � ������
#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Path {//���� ����� ������� ��� ����: ������ ��� ����� � ������ ������ ����� ����� ���� (return_xy)
  public:
    Path(const std::vector<Coords>& dots); //����� ������� ����������: ��������� ��� ����� ��� 
    Path(const Path&) = default;
    ~Path() = default;
    Coords return_xy(float pos) const;

  private:
  std::vector<Coords> dots;
};

class Road {//����� ������ ������ ������ ����� �� ��� � ���� �����(Path). ����� �� ����� ������� ���� � ��������� ����� � ������ ����
 public:
  Road(Path& path, std::vector<Ball>& balls);
  Road(const Road&) = default;
  ~Road() = default;
  void collide_check();
  void move();//������� ��� ����
  void gameOver(); //���������� ��� ���� � �����
  void checkGameOver(); //��������� ������������ � ������
  bool checkIfNewBallNeeded(); //��������� ���� ����� ����� ��� � ������ ����

 private:
  std::vector<std::unique_ptr<Ball>> balls;
  Path path;
};
