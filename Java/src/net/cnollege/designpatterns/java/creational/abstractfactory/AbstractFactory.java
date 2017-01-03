package net.cnollege.designpatterns.java.creational.abstractfactory;

/**
 * Created by mugen on 1/2/2017.
 */
public abstract class AbstractFactory {
    abstract IColor getColor(String color);
    abstract IShape getShape(String shape);
}
