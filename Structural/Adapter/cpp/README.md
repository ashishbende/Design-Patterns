# Adapter Design Pattern

* Allows two incompatible interfaces to work together
* Works by converting one interface to another

Use cases
* To integrate legacy code into your projects, when modifying legacy code is not possible.
  * Adapter class acts as a bridge between incompatible interfaces 

Pitfalls
* Introducing new intermediary classes
* Increased complexity
  * It introduces an additional wrapper around a class making code a bit difficult to understand.
* Unexpected behavior
* Performance overhead