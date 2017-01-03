package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public class VegBurger extends Burger {
    @Override
    public String name() {
        return "Fresh Veg Burger";
    }

    @Override
    public float price() {
        return 8.99f;
    }
}
