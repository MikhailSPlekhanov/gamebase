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
/*ѕлан по вычислению положени€ точки на кривой по длине пройденного пути
(вариант с затратами по пам€ти): ќбработка пути:
1. «адаем кривую массивом опорных точек, получаем аналитическую функцию кривой
от параметра t
2. ѕроходимс€ по кривой с достаточно малым шагом по t, вычисл€€ длину
пройденного пути.
3. „ерез равные, достачно малые промежутки, записываем новые опорные точки и их
отсто€ние от начала пути в массив размером N.
4. «аписываем полную длину пути L.
ѕолучение:
5. ѕолуча€ пройденный путь s, определ€ем приблизительный индекс в массиве как
int( N*s/L )
6. —равнени€ми обнаруживаем два элемента, между которыми лежит точка: (r1, s1) и
(r2, s2).
7. ”точн€ем положение как r = r1 + (r2-r1) * (s-s1) / (s2-s1). —тоит заметить,
что s2-s1 = const дл€ всего массива. */