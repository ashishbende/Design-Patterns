package net.cnollege.designpatterns.java.behavioral.strategy;

/**
 * Created by mugen on 1/7/17.
 * <p>
 * Strategy pattern : It defines & encapsulates family of algorithms and vary them interchangeably.
 */

public class Simulation {
    public static void main(String[] args) {
        MallardDuck mallardDuck = new MallardDuck();
        RubberDuck rubberDuck = new RubberDuck();

        rubberDuck.display();
        rubberDuck.performFly();
        System.out.println("*** Power up *** ");
        rubberDuck.setFlyBehavior(new FlyWithWings());
        rubberDuck.performFly();
    }
}
