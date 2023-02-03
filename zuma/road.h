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


class Road {//����� ������ ������ ������ ����� �� ���, ���� ����� � ���� �����(Path). ����� �� ����� ������� ���� � ��������� ����� � ������ ����
 public:
  Road(Path& path, std::vector<Ball>& balls, EndHole& endhole);
  Road(const Road&) = default;
  ~Road() = default;
  
  void insertBall(int i, Ball* ball);//��������� ��������� �� ��� ball �� ������� i � ������ ������� balls
  void move();//������� ��� ����
  void gameOver(); //���������� ��� ���� � �����
  void checkGameOver(); //��������� ������������ � ������
  bool checkForNewBall(); //��������� � ������ ������� ����� ��� ���� ����

  //������ � ������� Ball
  int getBallsSize() const;//���������� ����� ������� (����� ����� �� ������)

  void setBallCoords(int i, const Coords coords);//������������� ���������� i�� ���� � �������
  Coords getBallCoords(int i) const;//���������� ���������� i�� ���� � �������
  void setBallPosition(int i, const float x);//������������� pos i�� ���� � �������
  float getBallPosition(int i) const;//���������� pos i�� ���� � �������
  Colour getBallColour(int i) const;//���������� ���� i�� ���� � �������

  //������ � ������� Path
  float getPathLen() const;//���������� ����� ����
  float getPathDeltaPos() const;//���������� �������� � pos ����� ��������� ������

 
 private:
  std::vector<std::unique_ptr<Ball>> balls; //������ ������� ���� ������ ���, � ����� ����������� ����� ����.
  std::vector<std::unique_ptr<Ball>> ballsToGo; //������ ����� �� ������ �� ������.
  Path path;
  EndHole endhole;
};
