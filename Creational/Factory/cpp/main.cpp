#include <iostream>
using namespace std;

class Coffee{
 protected:
  char _type[20];
 public:
  Coffee(){}
  const char* getType()const{
    return _type;
  }
};

class Espresso : public Coffee{
 public:
  Espresso(){
    strcpy(_type, "Espresso");
    cout << "\nmaking a cup of espresso."<<endl;
    cout << "-- Grind and brew one scoop of espresso beans."<<endl;
  }
};

class Cappuccino: public Coffee{
 public:
  Cappuccino(){
    strcpy(_type, "Cappuccino");
    cout << "\nmaking a cup of cappuccino."<<endl;
    cout << "-- Grind and brew one scoop of espresso beans."<<endl;
    cout << "-- Heat and foam the milk."<<endl;
  }
};

class CoffeeMakerFactory{
 private:
  Coffee* _coffee;
 public:
  Coffee* GetCoffee(){
    int choice;
    cout << "Select the type of coffee : \n";
    cout << "1.Espresso \n2.Cappuccino \n Selection : ";
    cin >> choice;
    switch(choice){
      case 1:
        return new Espresso;
      case 2:
        return new Cappuccino;
      default:
        cout << "Invalid selection."<<endl;
        GetCoffee();
    }
  }
};
int main() {
  CoffeeMakerFactory coffeeMachine;
  Coffee *cup;
  cup = coffeeMachine.GetCoffee();
  cout << "Here's your cup of "<<cup->getType()<<endl;
  return 0;
}
