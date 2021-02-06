#include "person.hpp"
#include "ChatRoom.hpp"
#include <iostream>

Person::Person(const string& name): name(name){}

void Person::say(const string& message)const{
    room->broadcast(name, message);
}

void Person::private_message(const string& who, const string& msg) const{
    room->message(name, who, msg);
}

void Person::receive(const string& origin, const string& message){
    string s{origin +": \""+ message+"\""};
    cout << "[ " << name  << "'s chat session]"<<s << endl;
    chat_log.emplace_back(s);  
}

bool Person::operator==(const Person& rhs)const{
    return name == rhs.name;
}

bool Person::operator!=(const Person& rhs) const{
    return name != rhs.name;
}
