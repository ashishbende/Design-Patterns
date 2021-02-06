//
// Created by Ashish on 1/27/21.
//

#ifndef SRC_OBSERVER_H
#define SRC_OBSERVER_H
#include <string>
template<typename T>
class Observer {
public:
    virtual void field_changed(T& source, const std::string& field_name) = 0;
};


#endif //SRC_OBSERVER_H
