#include<iostream>
using namespace std;

struct Query{
    string creature_name;
    enum Argument{attack, defense} argument;
    int result;

    Query(const string &creatureName, Argument argument)
        : creature_name(creatureName), argument(argument){}
};


// observer pattern
template<typename T>
struct Signal{
    Signal(){
    }
    void operator()(T& query){
        cout << "I don't do anything here!" << endl;
    }
};

// mediator class
struct Game{
    Signal<Query&> queries;
};

class Creature{
    Game& game;
    int attack, defense;
    string name;
public:
    Creature(Game &game, int attack, int defense, const string &name)
    : game(game), attack(attack), defense(defense), name(name) {}

    int get_attack() const{
        Query q{name, Query::Argument::attack};
        game.queries(q);
        return q.result;
    }
    friend ostream& operator<<(ostream& os, const Creature& creature){
        os <<"Name: " <<creature.name <<", attack: " << creature.get_attack() << ", defense: " << creature.defense;
        return os;
    }
};


// subscribers
class CreatureModifiers{
    Game& game;
    Creature& creature;

public:
    CreatureModifiers(Game &game, Creature &creature) : game(game), creature(creature) {}
    virtual ~CreatureModifiers() = default;
};

struct connection{

};
class DoubleAttackModifier: public CreatureModifiers{
    connection conn;
public:
    DoubleAttackModifier(Game &game, Creature &creature)
        : CreatureModifiers(game, creature) {
        conn = game.queries.connect([&](Query& q){
            if(q.creature_name == creature.name && q.argument == Query::Argument::attack){
                q.attack *=2;
            }
        });
    }

    ~DoubleAttackModifier(){
        conn.disconnect(); // remove subscription
    }
};

int main(){

}