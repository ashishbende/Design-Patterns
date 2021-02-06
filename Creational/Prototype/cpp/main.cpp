#include <iostream>

class Animal{
 protected:
  char _hairColor[10];
  int _hairLength, _tail, _weight, _height, _age;
  int _intelligence, _stubbornness, _aggressiveness;

 public:
  virtual Animal* clone()=0;
  void SetHairColor(char* color){
    strcpy(_hairColor,color);
  }
  void SetHairLength(int hair_length) {
    _hairLength = hair_length;
  }
  void SetTail(int tail) {
    _tail = tail;
  }
  void SetWeight(int weight) {
    _weight = weight;
  }
  void SetHeight(int height) {
    _height = height;
  }
  void SetAge(int age) {
    _age = age;
  }
//  void SetIntelligence(int intelligence) {
//    _intelligence = intelligence;
//  }
//  void SetStubbornness(int stubbornness) {
//    _stubbornness = stubbornness;
//  }
//  void SetAggressiveness(int aggressiveness) {
//    _aggressiveness = aggressiveness;
//  }
};

class Sheep: public Animal{
 public:
  Sheep() {
    _age = 2;
    _hairLength = 5;
    _stubbornness = 2;
    _aggressiveness = 1;
    _intelligence = 7;
  }
  Animal *clone() override {
    return new Sheep();
  }

  // cutting hair
  void shearing(){
    _hairLength -=1;
  }
};

class Cow : public Animal{
 public:
  Cow() {
    _stubbornness=6;
    _intelligence=9;
    _aggressiveness=4;
  }
  Animal *clone() override {
    return new Cow();
  }
};
int main() {
  Sheep* sheep0 = new Sheep;
  sheep0->SetHairColor("white");
  sheep0->SetHairLength(10);
  sheep0->SetTail(5);
  sheep0->SetWeight(90);

  Cow* cow0 = new Cow;
  cow0->SetHairColor("Brown");
  cow0->SetWeight(700);
  cow0->SetHeight(2);
  cow0->SetTail(10);

  Animal* farm[3];
  farm[0] = sheep0->clone();
  farm[1] = cow0->clone();
  farm[1]->SetWeight(1000);

  sheep0->shearing();
  farm[2]=sheep0->clone();
}
