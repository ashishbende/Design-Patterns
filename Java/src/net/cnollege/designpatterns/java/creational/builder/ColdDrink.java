package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public abstract class ColdDrink implements IItem {

    @Override
    public IPacking packing() {
        return new Bottle();
    }

    @Override
    public abstract float price();
}
