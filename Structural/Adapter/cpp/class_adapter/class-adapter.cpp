#include <iostream>
#include <memory>

using namespace std;

// An abstract class
class Component {
 public:
  virtual void run() = 0;
  virtual ~Component() = default;
};

// Implemented by ComponentA
class ConcreteComponentA : public Component {
 public:
  virtual void run() override {
    cout << "Running ConcreteComponentA::run()" << endl;
  }
};

// Implemented by ComponentB
class ConcreteComponentB : public Component {
 public:
  virtual void run() override {
    cout << "Running ConcreteComponentB::run()" << endl;
  }
};

// Incompatible Class
class LegacyComponent {
 public:
  void slowRun() { cout << "Executing LegacyComponent::slowrun()" << endl; }
};

// Adapter class inherits both classes
class LegacyAdapter : public Component, private LegacyComponent {
 public:
  virtual void run() override {
    cout << "Executing LegacyAdapter::run() --> LegacyComponent::slowRun()"
         << endl;
    slowRun();
  }
};

int main() {
  const unique_ptr<Component> components[]{make_unique<ConcreteComponentA>(),
                                           make_unique<ConcreteComponentB>(),
                                           make_unique<LegacyAdapter>()};

  for (const auto &component : components) {
    component->run();
  }
  return 0;
}