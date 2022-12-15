#include "../graphics/graphics.h"
#include "../app/baseapp.h"
#include "../build/auxiliary.h"
#include "../build/road.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

const float COLLIDE_DISTANCE = 1;
const float ROAD_SPEED = 1;
const float RADIUS = 0.5;
const float dt = 1;

enum Colour { red = 0, green, blue, yellow };

class Cursor {
 public:
  float* return_pos() const {
    float pos[2] = {this->x, this->y};
    return pos;
  }

  void set_pos(){
      // getting position from special library and setting x,y
  };

 private:
  float x, y;
};

class Event {
 public:
  void process_mouse_click(Frog& frog) { frog.shoot(); }
};

class Info {
 public:
 private:
  float Frof_x, Frog_y;
  float* road_points;
};

class Level {
 public:
  
 private:
  bool state;
};

class Game {};

void main() {
  
}
/*���� �� ���������� ��������� ����� �� ������ �� ����� ����������� ����
(������� � ��������� �� ������): ��������� ����:
1. ������ ������ �������� ������� �����, �������� ������������� ������� ������
�� ��������� t
2. ���������� �� ������ � ���������� ����� ����� �� t, �������� �����
����������� ����.
3. ����� ������, �������� ����� ����������, ���������� ����� ������� ����� � ��
��������� �� ������ ���� � ������ �������� N.
4. ���������� ������ ����� ���� L.
���������:
5. ������� ���������� ���� s, ���������� ��������������� ������ � ������� ���
int( N*s/L )
6. ����������� ������������ ��� ��������, ����� �������� ����� �����: (r1, s1) �
(r2, s2).
7. �������� ��������� ��� r = r1 + (r2-r1) * (s-s1) / (s2-s1). ����� ��������,
��� s2-s1 = const ��� ����� �������. */