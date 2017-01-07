package net.cnollege.designpatterns.java.behavioral.strategy;

/**
 * Created by mugen on 1/7/17.
 */
public class Squeak implements QuackBehavior {
    @Override
    public void quack() {
        System.out.println("Squeak!!");
    }
}