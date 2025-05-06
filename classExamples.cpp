#include "classExamples.h"
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    void setValues(int, int);
    int area() {
      return width*height;
    }
};

void Rectangle::setValues(int w, int h) {
  width = w;
  height = h;
}

void classExample() {
  Rectangle rect;
  rect.setValues(3, 4);
  cout << "area: " << rect.area() << endl;
}
