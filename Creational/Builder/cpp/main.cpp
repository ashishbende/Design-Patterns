#include <iostream>

using namespace std;

// main item in a combo meal
class Entree{
 protected:
  char _entree[10];
 public:
  const char* getEntree() const {
    return _entree;
  }
};

class Burger : public Entree{
 public:
  Burger(){
    cout  << "\n 1. Grill burger patty"
          << "\n 2. Add tomatoes"
          << "\n 3. Put these all bug.";
    strcpy(_entree, "hamburger");
  }
};

class Hotdog : public Entree{
 public:
  Hotdog(){
    cout  << "\n 1. Cook sausage."
          << "\n 2. Put it in a bug";
    strcpy(_entree, "hotdog");
  }
};

class Side{
 protected:
  char _side[10];
 public:
  const char* getSide() const {
    return _side;
  }
};

class Fries: public Side{
 public:
  Fries(){
    cout << "\n Fry and season potatoes.";
    strcpy(_side, "Fries");
  }
};

class Salad: public Side{
 public:
  Salad(){
    cout << "\n Toss greens and dressing together.";
    strcpy(_side, "salad");
  }
};

class Drink{
 protected:
  char _drink[10];
 public:
  Drink(){
    cout << "\n Fill cup with soda.";
    strcpy(_drink, "Soda");
  }
  const char* getDrink() const {
    return _drink;
  }
};

class MealCombo{
 private:
  Entree* entree;
  Side* side;
  Drink* drink;
  char _bag[100];

 public:
  MealCombo(const char* type){
    sprintf(_bag, "\n %s meal combo", type);
  }
  void SetEntree(Entree *entree) {
    MealCombo::entree = entree;
  }
  void SetSide(Side *side) {
    MealCombo::side = side;
  }
  void SetDrink(Drink *drink) {
    MealCombo::drink = drink;
  }
  const char* openMealBag(){
    sprintf(_bag, "%s %s %s %s",_bag, entree->getEntree(), side->getSide(), drink->getDrink());
    return _bag;
  }
};

class MealBuilder{
 protected:
  MealCombo * _meal;
 public:
  virtual void cookEntree(){};
  virtual void cookSide(){};
  virtual void fillDrink(){};
  MealCombo *GetMeal() const {
    return _meal;
  }
};

class BurgerMeal : public MealBuilder{
 public:
  BurgerMeal(){
    _meal = new MealCombo("Burger");
  }
  void cookEntree() override {
    Burger* burger = new Burger;
    _meal->SetEntree(burger);
  }

  void cookSide() override {
    Fries* fries = new Fries;
    _meal->SetSide(fries);
  }

  void fillDrink() override {
    Drink* drink = new Drink;
    _meal->SetDrink(drink);
  }
};

class HotdogMeal : public MealBuilder{
 public:
  HotdogMeal(){
    _meal = new MealCombo("Hotdog");
  }
  void cookEntree() override {
    Hotdog* hotdog = new Hotdog;
    _meal->SetEntree(hotdog);
  }
  void cookSide() override {
    Salad* salad = new Salad;
    _meal->SetSide(salad);
  }
  void fillDrink() override {
    Drink* drink = new Drink;
    _meal->SetDrink(drink);
  }
};

int main() {
  MealBuilder* cook1 = new MealBuilder;
  MealBuilder* cook2 = new MealBuilder;
  MealCombo* burgerCombo;
  MealCombo* hotdogCombo;

  cook1 = new BurgerMeal;
  cook1->cookEntree();
  cook1->cookSide();
  cook1->fillDrink();
  burgerCombo = cook1->GetMeal();
  cout << burgerCombo->openMealBag() << endl;

  cook2 = new HotdogMeal;
  cook2->cookEntree();
  cook2->cookSide();
  cook2->fillDrink();
  hotdogCombo = cook2->GetMeal();
  cout << hotdogCombo->openMealBag() << endl;

  return 0;
}
