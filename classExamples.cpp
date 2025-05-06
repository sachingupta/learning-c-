#include "classExamples.h"
#include <iostream>
using namespace std;

/*
This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void.
*/

/*
Rectangle rectb;   // default constructor called
Rectangle rectc(); // function declaration (default constructor NOT called)
Rectangle rectd{}; // default constructor called 
*/

/*
Member initialization in constructors
Rectangle::Rectangle (int x, int y) { width=x; height=y; }

Rectangle::Rectangle (int x, int y) : width(x) { height=y; }

Rectangle::Rectangle (int x, int y) : width(x), height(y) { }

*/

class Rectangle {
    int width, height;
  public:
    Rectangle();
    Rectangle(int, int);
    int area() {
      return width*height;
    }
};

Rectangle::Rectangle() {
  width = 5;
  height = 5;
}

Rectangle::Rectangle(int w, int h) {
  width = w;
  height = h;
}

void classExample() {
  Rectangle rect(3,4), rectb;
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
}
void classExample3() {
  Rectangle obj (3, 4);
  Rectangle * foo, * bar, * baz;
  foo = &obj;
  bar = new Rectangle (5, 6);
  baz = new Rectangle[2] { {2,5}, {3,6} };
  cout << "obj's area: " << obj.area() << '\n';
  cout << "*foo's area: " << foo->area() << '\n';
  cout << "*bar's area: " << bar->area() << '\n';
  cout << "baz[0]'s area:" << baz[0].area() << '\n';
  cout << "baz[1]'s area:" << baz[1].area() << '\n';       
  delete bar;
  delete[] baz;
}

class Circle {
    double radius;
  public:
    Circle(double r) { radius = r; }
    double circum() {return 2*radius*3.14159265;}
};

int classExample2 () {
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';
}
