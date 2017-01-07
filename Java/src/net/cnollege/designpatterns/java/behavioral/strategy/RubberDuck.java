package net.cnollege.designpatterns.java.behavioral.strategy;

/**
 * Created by mugen on 1/7/17.
 */
public class RubberDuck extends Duck {

    public RubberDuck() {
        flyBehavior = new FlyNoWay();
        quackBehavior = new Squeak();
    }

    @Override
    void display() {
        System.out.println("I'm a rubber duck!");
    }
}
