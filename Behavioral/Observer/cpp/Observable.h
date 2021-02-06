//
// Created by Ashish on 1/27/21.
//

#ifndef SRC_OBSERVABLE_H
#define SRC_OBSERVABLE_H
#include <vector>
#include <string>
#include<iostream>

// forward declaration
template<typename T>
class Observer;

template<typename T>
class Observable {
    std::vector<Observer<T>*> subscribers;
public:
    void notify(T& source, const std::string& field_name){
        for(auto observer: subscribers){
            observer->field_changed(source, field_name);
        }
    }

    void subscribe(Observer<T>& observer){
        subscribers.push_back(&observer);
    }

    void unsubscribe(Observer<T>& observer){
        subscribers.erase(std::remove(subscribers.begin(), subscribers.end(), &observer), subscribers.end());
        std::cout << "unsubscribed!"<<std::endl;
    }
};


#endif //SRC_OBSERVABLE_H
