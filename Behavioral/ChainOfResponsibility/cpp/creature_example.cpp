#include <iostream>
#include <string>


using namespace std;
struct Creature{
    string name;
    int attack, defense;

    Creature(const string& name, int attack, int defense)
    :name(name), attack(attack), defense(defense){}

    friend ostream& operator<<(ostream& os, const Creature& creature){
        os << "name: "<< creature.name << ", has attack  : " << creature.attack << ", and defense : "
        << creature.defense;
        return os;
    }
};

class CreatureModifier{
    CreatureModifier* next{nullptr};
protected:
    Creature& creature;
public:
    CreatureModifier(Creature& creature): creature(creature){}
    void add_to_chain(CreatureModifier* nextModifier){
        // check if there's a next
        if(next) next->add_to_chain(nextModifier);
        else next = nextModifier;
    }

    virtual void handle(){
        if(next) next->handle();
    }
};

class DoubleAttackModifier: public CreatureModifier{
public:
    DoubleAttackModifier(Creature& creature) : CreatureModifier(creature){}
    // implement override method
    void handle() override {
        creature.attack *=2; // double attack strength
        // walk chain of responsibility
        CreatureModifier::handle();
    }
};

class IncreaseDefenseModifier: public CreatureModifier{
public:
    IncreaseDefenseModifier(Creature& creature) : CreatureModifier(creature){}
    void handle()override{
        if(creature.attack<=2)
            creature.defense++;
        CreatureModifier::handle();
    }
};

class NoBonusesModifier: public CreatureModifier{
public:
    NoBonusesModifier(Creature &creature) : CreatureModifier(creature) {}

    void handle() override {
        cout << "Cursed! " << endl;
        // don't propagate the chain of responsibility
        //CreatureModifier::handle();
    }
};

int main() {
    Creature goblin{"Goblin",1,1};
    cout << goblin << endl;
    CreatureModifier rootModifier{goblin};

    // define different modifiers
    DoubleAttackModifier dAMod{goblin};
    DoubleAttackModifier dAMod_2{goblin};
    IncreaseDefenseModifier incDef{goblin};

    // add to root modifiers
    rootModifier.add_to_chain(&dAMod);
    rootModifier.add_to_chain(&dAMod_2);
    rootModifier.add_to_chain(&incDef); // no-op

    // invoke chain of responsibility
    rootModifier.handle();
    cout << goblin << endl;

    Creature hero_gobin{"HeroGoblin", 2, 1};
    cout << hero_gobin << endl;
    NoBonusesModifier curse{hero_gobin};
    CreatureModifier rootModifier2{hero_gobin};

    rootModifier2.add_to_chain(&curse);
    rootModifier2.add_to_chain(&dAMod);
    rootModifier2.add_to_chain(&incDef);

    rootModifier2.handle();
    cout << hero_gobin << endl;


    return 0;
}
