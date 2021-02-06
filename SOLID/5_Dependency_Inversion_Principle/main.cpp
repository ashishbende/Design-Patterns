/*
 *  1. A high level module should not depend on low level modules.
 *  Both should depend on abstractions.
 *
 *  2. Abstractions should not depend on details,
 *  rather details should depend on abstractions.
 * */

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

enum class RelationshipType{
  parent, child, sibling
};

struct Person{ string name;};


// fixing by adding an abstraction -
struct RelationshipBrowser{
  virtual vector<Person> find_all_children_of(const string& name )=0;
};

// low-level module
struct Relationships : RelationshipBrowser{
  vector<tuple<Person,RelationshipType,Person>> relations;
  void add_parent_and_child(const Person& parent, const Person& child){
    relations.push_back({parent,RelationshipType::parent,child});
    relations.push_back({child,RelationshipType::child,parent});
  }
  vector<Person> find_all_children_of(const string &name) override {
    vector<Person> result;
    for(auto&& [first, rel, second] : relations){
      if(first.name == name && rel == RelationshipType::parent){
        //cout << first.name << " is parent of " << second.name << endl;
        result.push_back(second);
      }
    }
    return result;
  }
};

// high-level module
struct Research{
  // breaking the principle here (high level module, depending on low-level module)
  // any changes in the low-level module will break this code
  //  Research(Relationships& rel ){
  //    auto& relations = rel.relations;
  //    for(auto&& [first, rel, second] : relations){
  //      if(first.name == "Peter" && rel == RelationshipType::parent){
  //        cout << "Peter is parent of " << second.name << endl;
  //      }
  //    }
  //  }

  Research(RelationshipBrowser& browser){
    for(auto& child : browser.find_all_children_of("Peter")){
      cout << " Peter has a child called " << child.name << endl;
    }
  }
};



int main() {
  Person parent{"Peter"};
  Person child1{"Chris"}, child2{"Meg"}, child3{"Stewie"};

  Relationships relationships;
  relationships.add_parent_and_child(parent,child1);
  relationships.add_parent_and_child(parent,child2);
  relationships.add_parent_and_child(parent,child3);

  Research _(relationships);

  return 0;
}
