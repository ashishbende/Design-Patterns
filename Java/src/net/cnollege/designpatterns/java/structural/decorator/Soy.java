package net.cnollege.designpatterns.java.structural.decorator;

/**
 * Created by mugen on 1/7/17.
 */
public class Soy extends CondimentDecorator {

    private Beverage beverage;

    public Soy(Beverage beverage) {
        this.beverage = beverage;
    }

    @Override
    public String getDescription() {
        return beverage.getDescription() + ", Soy";
    }

    @Override
    public double cost() {
        return 0.10 + beverage.cost();
    }
}
