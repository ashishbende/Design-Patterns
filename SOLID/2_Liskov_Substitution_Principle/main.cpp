/* Any derived class should be substitutable for a function
 * that accepts a base class. Example, process function here.
 * */

#include <iostream>
using namespace std;
class Rectangle{
 protected:
  int width, height;
 public:
  Rectangle(int width, int height) : width(width), height(height) {}
  int GetWidth() const {
    return width;
  }
  virtual void SetWidth(int width) {
    Rectangle::width = width;
  }
  int GetHeight() const {
    return height;
  }
  virtual void SetHeight(int height) {
    Rectangle::height = height;
  }

  int area() const {return Rectangle::width*Rectangle::height;}
};

void process(Rectangle& r){
  int w = r.GetWidth();
  r.SetHeight(10);

  cout  << "Expected area = " << (w*10)
        << ", got = " << r.area() << endl;
}


class Square: public Rectangle{
 public:
  Square(int size):Rectangle(size,size){}
  // although correct, but it violets liskov's substitution principle
  void SetWidth(int width) override {
    Rectangle::width = Rectangle::height = width;
  }
  void SetHeight(int height) override {
    Rectangle::height = Rectangle::width = height;
  }
};


// ways to fix ->
// 1. a bool flag indicating whether rectangle is a square or not
// 2. creating a Rectangle Factory

struct RectangleFactory{
  static Rectangle create_rectangle(int w, int h);
  static Rectangle create_square(int s);
};

int main() {
  Rectangle r{3,4};
  process(r);

  Square sq{5};
  process(sq);
  return 0;
}
