package net.cnollege.designpatterns.java.behavioral.strategy;

/**
 * Created by mugen on 1/7/17.
 */
public class Quack implements QuackBehavior {
    @Override
    public void quack() {
        System.out.println("Quack!");
    }
}
