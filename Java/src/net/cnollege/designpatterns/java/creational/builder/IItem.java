package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public interface IItem {
    String name();

    IPacking packing();

    float price();
}
