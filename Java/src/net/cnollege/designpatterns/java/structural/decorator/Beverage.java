package net.cnollege.designpatterns.java.structural.decorator;

/**
 * Created by mugen on 1/7/17.
 */
public abstract class Beverage {
    String description = "Unknown beverage";

    public String getDescription() {
        return description;
    }

    public abstract double cost();
}
