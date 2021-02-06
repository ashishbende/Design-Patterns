#include <iostream>
#include "Observer.h"
#include "Observable.h"

// observable - entity which could be monitored
class Person : public Observable<Person>{
    int age;
public:
    Person(int age) : age(age) {}

    int get_age() const{
        return age;
    }
    void set_age(int age){
        if(this->age == age) return;

        auto old_can_vote = get_can_vote();
        this->age = age;
        notify(*this, "age");
        if(old_can_vote != get_can_vote())
            notify(*this, "can_vote");
    }

    bool get_can_vote() const{
        return age>=16;
    }
};

class ConsolePersonObserver : public Observer<Person>{
public:
    void field_changed(Person& source, const std::string& field_name) override{
        std::cout << "Person's "<<field_name << " has changed to ";
        if(field_name == "age") std::cout << source.get_age();
        if(field_name == "can_vote") std::cout << std::boolalpha << source.get_can_vote();
        std::cout << "\n";
    }
};


// observer -- that thing which wants to monitor
int main() {
    Person person{10};
    ConsolePersonObserver cobsrv;
    person.subscribe(cobsrv);

    person.set_age(11);
    person.set_age(12);
    person.unsubscribe(cobsrv);
    person.set_age(13);
    return 0;
}
