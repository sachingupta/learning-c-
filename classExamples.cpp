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
void classPointerExample() {
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

void clasaMemberInitializationExamples () {
  Circle foo (10.0);   // functional form
  Circle bar = 20.0;   // assignment init.
  Circle baz {30.0};   // uniform init.
  Circle qux = {40.0}; // POD-like

  cout << "foo's circumference: " << foo.circum() << '\n';
}


class CartseianVector {
  public:
    int x, y;
    CartseianVector() {};
    CartseianVector(int a, int b) : x(a), y(b) {}
    CartseianVector operator + (const CartseianVector& param) {
      CartseianVector temp;
      temp.x = x + param.x;
      temp.y = y + param.y;
      return temp;
    }

    CartseianVector& operator= (const CartseianVector& param)
    {
      x=param.x;
      y=param.y;
      return *this;
    }
};

// non member operator overloading
CartseianVector operator- (const CartseianVector& lhs, const CartseianVector& rhs) {
  CartseianVector temp;
  temp.x = lhs.x - rhs.x;
  temp.y = lhs.y - rhs.y;
  return temp;
}

/*
type operator sign (parameters) { ... body ... }
*/ 
void classOperatorOverloadingExample() {
  CartseianVector a(3 , 1);
  CartseianVector b(1, 2);
  CartseianVector sum, subtraction;
  sum = a + b; // c = a.operator+ (b);
  cout << "sum " << sum.x << ", " << sum.y << endl;

  subtraction = a - b; // c = a.operator+ (b);
  cout << "subtraction: " << subtraction.x << ", " << subtraction.y << endl;
}


class Dummy {
  public:
    static int n;
    Dummy () { n++; };
};

/*
In fact, static members have the same properties as non-member variables but they enjoy class scope. For that reason, and to avoid them to be declared several times, they cannot be initialized directly in the class, but need to be initialized somewhere outside it. As in the previous example:
*/
int Dummy::n=0;

void staticClasaMemberExamples () {
  Dummy a;
  Dummy b[5];
  /*Because it is a common variable value for all the objects of the same class, it can be referred to as a member of any object of that class or even directly by the class name (of course this is only valid for static members):*/
  cout << a.n << '\n';
  Dummy * c = new Dummy;
  cout << Dummy::n << '\n';
  delete c;
}

template <class T>
class MyPair {
  T a,b;
  public: 
    MyPair(T first, T second) {
      a = first;
      b = second;
    }
    T getMax() {
      T result;
      result = a > b ? a : b;
      return result;
    }
};

void classTemplateExamples() {
  MyPair<int> myPair1 (100, 75);
  MyPair<float> myPair2(3.3, 3.333);
  cout << "int: " << myPair1.getMax() << endl;
  cout << "float: " << myPair2.getMax() << endl;
}

void classExamples() {
  // classExample();
  // classPointerExample();
  // clasaMemberInitializationExamples();
  // classOperatorOverloadingExample();
  // staticClasaMemberExamples();
  classTemplateExamples();
}
