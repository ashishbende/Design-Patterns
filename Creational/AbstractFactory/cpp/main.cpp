#include <iostream>
using namespace std;

class Door{
 public:
  Door(){}
  virtual void Open()=0;
};

class GasCarDoor : public Door{
 public:
  GasCarDoor(){
    cout << "Making a door for a gas car." <<endl;
  }
  void Open()override{
    cout << "click" << endl;
  }
};
class ElectricCarDoor : public Door{
 public:
  ElectricCarDoor(){
    cout << "Making a door for an electric car." <<endl;
  }
  void Open()override{
    cout << "sshhhh" << endl;
  }
};

class Engine{
 protected:
  char _sound[20];
 public:
  Engine(){
    strcpy(_sound,"");
  }
  virtual void Run() = 0;
};

class GasEngine : public  Engine{
 public:
  GasEngine(){
    cout << "Making a gas engine!" <<endl;
    strcpy(_sound, "vrooom!");
   }
   void Run(){
    cout << _sound << endl;
  }
};

class ElectricEngine : public  Engine{
 public:
  ElectricEngine(){
    cout << "Making a electric induction engine!" <<endl;
    strcpy(_sound, "sshhh...!");
  }
  void Run(){
    cout << _sound << endl;
  }
};

class CarFactory{
 public:
  virtual Door* BuildDoor()=0;
  virtual Engine* BuildEngine()=0;
};

class GasCarFactory : public CarFactory{
 public:
  GasCarFactory(){}
  Door *BuildDoor() override {
    return new GasCarDoor();
  }
  Engine *BuildEngine() override {
    return new GasEngine();
  }
};

class ElectricCarFactory : public CarFactory{
 public:
  ElectricCarFactory(){}
  Door *BuildDoor() override {
    return new ElectricCarDoor();
  }
  Engine *BuildEngine() override {
    return new ElectricEngine();
  }
};
int main() {
  CarFactory* carPlant1;
  carPlant1 = new GasCarFactory();
  Door* d1 = carPlant1->BuildDoor();
  Engine* e1 = carPlant1->BuildEngine();
  // test drive!
  d1->Open();
  e1->Run();

  CarFactory* carPlant2;
  carPlant2 = new ElectricCarFactory();
  Door* d2 = carPlant2->BuildDoor();
  Engine* e2 = carPlant2->BuildEngine();
  // test drive!
  d2->Open();
  e2->Run();

  return 0;
}
