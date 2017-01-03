package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public class ChickenBurger extends Burger {
    @Override
    public String name() {
        return "Spicy Chicken Burger";
    }

    @Override
    public float price() {
        return 10.99f;
    }
}
