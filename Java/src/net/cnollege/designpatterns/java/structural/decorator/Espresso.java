package net.cnollege.designpatterns.java.structural.decorator;

/**
 * Created by mugen on 1/7/17.
 */
public class Espresso extends Beverage {

    public Espresso() {
        description = "Espresso coffee";
    }

    @Override
    public double cost() {
        return 1.99;
    }
}
