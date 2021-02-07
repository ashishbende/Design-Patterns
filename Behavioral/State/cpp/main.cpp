#include <iostream>

using namespace std;
class LightSwitch;
class State{
public:
    virtual void on(LightSwitch* ls){
        cout << "Light is already on!" << endl;
    }
    virtual void off(LightSwitch* ls){
        cout << "Light is already off!" << endl;
    }

};

class OnState: public State{
public:
    OnState() {
        cout << "Light is on!" << endl;
    }
    void off(LightSwitch *ls) override;
};

class OffState: public State{
public:
    OffState() {
        cout << "Light is off!" << endl;
    }
    void on(LightSwitch *ls) override;
};

class LightSwitch{
    State* currentState;
public:
    LightSwitch() {
        currentState = new OffState();
    }

    void set_state(State* s){
        this->currentState = s;
    }
    void on(){
        currentState->on(this);
    }

    void off(){
        currentState->off(this);
    }

};

void OnState::off(LightSwitch *ls)  {
    cout << "Switching light off...\n";
    ls->set_state(new OnState());
    delete this;
}

void OffState::on(LightSwitch *ls)  {
    cout << "Switching light on...\n";
    ls->set_state(new OffState());
    delete this;
}
int main() {
    LightSwitch ls;
    ls.on();
    ls.off();
    ls.off();
    return 0;
}
