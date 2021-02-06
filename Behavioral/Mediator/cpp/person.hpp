#ifndef __PERSON_H
#define __PERSON_H

#include<string>
#include<vector>
using namespace std;

struct ChatRoom;

struct Person{
    string name;
    ChatRoom* room{nullptr};
    vector<string> chat_log;
    Person(const string& name);
    void say(const string& msg) const;
    void private_message(const string& who, const string& msg) const;
    void receive(const string& origin, const string& message);

    bool operator==(const Person &rhs)const;
    bool operator!=(const Person &rhs)const;
};

#endif