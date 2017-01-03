package net.cnollege.designpatterns.java.creational.abstractfactory;

/**
 * Created by mugen on 1/2/2017.
 */
public class ShapeFactory extends AbstractFactory{
    @Override
    public IShape getShape(String shapeName){
        if(shapeName.equalsIgnoreCase("Circle")) return new Circle();
        if(shapeName.equalsIgnoreCase("Rectangle")) return new Rectangle();
        if(shapeName.equalsIgnoreCase("Triangle")) return new Triangle();
        else return null;
    }

    @Override
    public IColor getColor(String colorName){
        return null;
    }
}
