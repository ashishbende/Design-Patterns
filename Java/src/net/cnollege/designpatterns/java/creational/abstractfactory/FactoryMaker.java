package net.cnollege.designpatterns.java.creational.abstractfactory;

/**
 * Created by mugen on 1/2/2017.
 */
public class FactoryMaker {
    public static AbstractFactory makeFactory(String factoryType){
        if(factoryType.equalsIgnoreCase("Shape"))return new ShapeFactory();
        if(factoryType.equalsIgnoreCase("Color"))return new ColorFactory();
        else return null;
    }
}
