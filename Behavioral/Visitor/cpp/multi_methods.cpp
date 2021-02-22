#include <iostream>
#include <typeindex>
#include <map>
using namespace std;

struct GameObject;
void collide(GameObject &first, GameObject &second);

struct GameObject{
    virtual type_index type() const = 0;
    virtual void collide(GameObject &other){
        ::collide(*this, other);
    }
};

template<typename T> struct GameObjectImpl : GameObject{
    type_index type() const override{
        return typeid(T);
    }
};

//CRTP
struct Planet :GameObjectImpl<Planet>{

};

struct Asteroid :GameObjectImpl<Asteroid>{

};

struct Spaceship :GameObjectImpl<Spaceship>{

};

void spaceship_planet(){cout << "Spaceship lands on planet\n";}
void asteroid_planet(){cout << "asteroid burns up in atmosphere\n";}
void asteroid_spaceship(){cout << "asteroid hits and destroys spaceship\n";}

map<pair<type_index, type_index>, void(*)(void)> outcomes{
        {{typeid(Spaceship), typeid(Planet)}, spaceship_planet},
        {{typeid(Asteroid), typeid(Planet)}, asteroid_planet},
        {{typeid(Asteroid), typeid(Spaceship)}, asteroid_spaceship},
};

void collide(GameObject &first, GameObject &second){
    auto it = outcomes.find({first.type(), second.type()});
    if(it == outcomes.end()) {
        auto it = outcomes.find({second.type(), first.type()});
        if(it == outcomes.end()){
            cout << "Nothing happens!\n";
        }
    }
    it->second();
}


int main(){
    Asteroid asteroid;
    Planet planet;
    Spaceship spaceship;

    collide(asteroid,planet);
    collide(planet,spaceship);
    collide(asteroid,spaceship);
}