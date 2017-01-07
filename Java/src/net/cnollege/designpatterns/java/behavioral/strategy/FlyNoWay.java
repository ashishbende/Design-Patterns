package net.cnollege.designpatterns.java.behavioral.strategy;

/**
 * Created by mugen on 1/7/17.
 */
public class FlyNoWay implements FlyBehavior {
    @Override
    public void fly() {
        System.out.println("Man, I can't fly!");
    }
}
