#pragma once

#include "auxiliary.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Path { //����� ����: ���������� ����� ������ � ������������ �������������� � ���
 public:
  Path(const std::vector<Coords>& dots);
  Path(const Path&) = default;
  ~Path() = default;

  Coords return_xy(const float& pos) const; //���������� ���������� �� ������� pos
  float getLen() const; // ���������� ����� ����
  float getDpos() const; // ���������� dpos
  Coords getDotCoords(int i); // ���������� ���������� i�� ������� �����
  int getDotsSize(); //���������� ���������� ������� �����

 private:
  std::vector<Coords> dots; //������� ����� �� ������� ���������� ���������� ����������
  float len; //����� ����
  float dpos; //�������� � pos ����� ��������� ������
};


class Road {//����� ������: ������ ������ ����� �� ���, ���� ����� � ���� �����(Path). ����� �� ����� ������� ���� � ��������� ����� � ������ ����
 public:
  Road(Path& path);
  Road(const Road&) = default;
  ~Road() = default;
  
  void insertBall(int i, Ball& ball);//��������� ��������� �� ��� ball �� ������� i � ������ ������� balls
  void move();//������� ��� ����
  bool checkGameOver(); //��������� ������������ � ������
  void addNewBall(); //��������� � ������ ������� ����� ��� ���� ����

  //������ � ������� Ball
  int getBallsSize() const;//���������� ����� ������� (����� ����� �� ������)

  void setBallCoords(int i, const Coords coords);//������������� ���������� i�� ���� � �������
  Coords getBallCoords(int i) const;//���������� ���������� i�� ���� � �������
  void setBallPosition(int i, const float x);//������������� pos i�� ���� � �������
  float getBallPosition(int i) const;//���������� pos i�� ���� � �������
  Colour getBallColour(int i) const;//���������� ���� i�� ���� � �������

  //������ � ������� Path
  float getPathLen() const;//���������� ����� ����
  float getPathDpos() const;//���������� �������� � pos ����� ��������� ������

 
 private:
  std::vector<std::unique_ptr<Ball>> balls; //������ ����� �� ������. ������ ������� ���� ������ ���, � ����� ����������� ����� ����
  std::vector<std::unique_ptr<Ball>> ballsToGo; //������ ����� �� ������ �� ������. ��������� � ������� ��� ���, ������� �������� �� ������
  Path path;
  EndHole endhole;
  EndHole beginhole;
};
