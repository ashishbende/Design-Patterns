package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public abstract class Burger implements IItem {
    @Override
    public IPacking packing() {
        return new Wrapper();
    }

    @Override
    public abstract float price();

}
