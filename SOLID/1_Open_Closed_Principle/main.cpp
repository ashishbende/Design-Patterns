/* A system should be open to extension but close for modification.
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Color{red, green, blue};
enum class Size{small, medium, large};


struct Product{
  string name;
  Color color;
  Size size;
};


// here we are breaking open-closed principle
struct ProductFilter{
  // all these new filters are requiring us to modify the product filer struct each time
  static vector<Product*> by_color(vector<Product*>& items, Color color){
    vector<Product*> result;
    for(auto& i: items){
      if(color == i->color){
        result.push_back(i);
      }
    }
    return result;
  }

  static vector<Product*> by_size(vector<Product*>& items, Size size){
    vector<Product*> result;
    for(auto& i: items){
      if(size == i->size){
        result.push_back(i);
      }
    }
    return result;
  }

  static vector<Product*> by_color_and_size(vector<Product*>& items, Color color, Size size){
    vector<Product*> result;
    for(auto& i: items){
      if(color == i->color && size == i->size){
        result.push_back(i);
      }
    }
    return result;
  }
};

// using specification pattern

template<typename T>
struct Specification{
  virtual bool is_satisfied(T* item) = 0;
};

template<typename T>
struct Filter{
  virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product>{
  vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override {
    vector<Product *> result;
    for(auto& i : items){
      if(spec.is_satisfied(i)){
        result.push_back(i);
      }
    }
    return result;
  }
};

struct ColorSpec : Specification<Product>{
  Color color;
  explicit ColorSpec(Color color) : color(color) {}
  bool is_satisfied(Product *item) override {
    return color == item->color;
  }
};

struct SizeSpec : Specification<Product>{
  Size size;
  explicit SizeSpec(Size size) : size(size){}
  bool is_satisfied(Product* item) override{
    return size == item->size;
  }
};

template<typename T>
struct AndSpec : Specification<T>{
  Specification<T>& sp1;
  Specification<T>& sp2;
  AndSpec(Specification<T> &sp_1, Specification<T> &sp_2) : sp1(sp_1), sp2(sp_2) {}
  bool is_satisfied(T *item) override {
    return sp1.is_satisfied(item) && sp2.is_satisfied(item);
  }
};


int main() {
  Product apple{"apple",Color::red, Size::large};
  Product tree{"tree", Color::green, Size::small};
  Product house{"house", Color::blue, Size::medium};
  Product mountain{"Mountain", Color::green, Size::large};

  vector<Product*> items{&apple, &tree, &house, &mountain};
  auto greenStuffs = ProductFilter::by_color(items, Color::green);
  for(auto& i : greenStuffs){
    cout << i->name << endl;
  }

  BetterFilter bf;
  ColorSpec greenSpec(Color::green);
  auto greenThings = bf.filter(items,greenSpec);
  for(auto& i : greenThings){
    cout << i->name << " is green."   << endl;
  }

  SizeSpec largeSpec(Size::large);
  AndSpec<Product> greenAndLarge(greenSpec, largeSpec);
  auto greenAndLargeStuff = bf.filter(items, greenAndLarge);
  for(auto& i : greenAndLargeStuff){
    cout << i->name << " is green and large."   << endl;
  }
  return 0;
}
