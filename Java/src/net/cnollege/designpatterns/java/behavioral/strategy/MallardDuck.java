package net.cnollege.designpatterns.java.behavioral.strategy;

/**
 * Created by mugen on 1/7/17.
 */
public class MallardDuck extends Duck {

    public MallardDuck() {
        quackBehavior = new Quack();
        flyBehavior = new FlyWithWings();
    }

    @Override
    void display() {
        System.out.println("I'm Mallard duck!");
    }
}
