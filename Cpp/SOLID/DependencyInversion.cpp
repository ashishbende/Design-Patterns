#include <iostream>
#include <tuple>
#include <vector>
/*  1. high level modules should not depend on low-level modules both should
   depend on an abstraction.
    2. abstractions should not depend on details, but otherway around
*/

enum class Relationship { parent, child, sibling };

struct Person {
  std::string name;
};

// better way - abstraction
struct RelationshipBrowser {
  virtual std::vector<Person> find_all_children_of(const std::string &name) = 0;
};

// we define a construct to maintain relationship info
// this low level module
struct Relationships : RelationshipBrowser {
  std::vector<std::tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person &parent, const Person &child) {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }
  std::vector<Person> find_all_children_of(const std::string &name) override {
    std::vector<Person> result;
    for (auto &&[first, rel, second] : relations) {
      // if we trying to find the parents
      if (first.name == name && rel == Relationship::parent) {
        result.push_back(second);
      }
    }
    return result;
  }
};

// high level module
struct Research {
  Research(RelationshipBrowser &relBrowser) {
    for (auto &child : relBrowser.find_all_children_of("John")) {
      std::cout << "John has a child named " << child.name << std::endl;
    }
    // BAD! if low-level module decides to changes the ds,
    // this could will break
    // auto& relations = rel.relations;
    // for(auto&& [first, rel, second] : relations){
    //     // if we trying to find the parents
    //     if(first.name == "John" && rel == Relationship::parent){
    //         std::cout << "John has a child " << second.name << std::endl;
    //     }
    // }
  }
};

int main() {
  Person parent{"John"};
  Person child1{"Chris"}, child2{"Matt"};

  Relationships rel;
  rel.add_parent_and_child(parent, child1);
  rel.add_parent_and_child(parent, child2);

  Research research(rel);
}
