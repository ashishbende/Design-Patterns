package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public class Coke extends ColdDrink {
    @Override
    public String name() {
        return "Diet Coke";
    }

    @Override
    public float price() {
        return 1.99f;
    }
}
