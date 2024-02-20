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

// Adapter
class LegacyAdapter : public Component {
 private:
  unique_ptr<LegacyComponent> m_adoptee;

 public:
  LegacyAdapter() : m_adoptee(make_unique<LegacyComponent>()) {}
  virtual void run() override {
    cout << "LegacyAdapter::run() --> Calling LegacyComponent::slowRun()"
         << endl;
    m_adoptee->slowRun();
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
