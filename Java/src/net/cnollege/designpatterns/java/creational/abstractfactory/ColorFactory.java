package net.cnollege.designpatterns.java.creational.abstractfactory;

/**
 * Created by mugen on 1/2/2017.
 */
public class ColorFactory extends AbstractFactory {
    @Override
    public IShape getShape(String shapeName){
         return null;
    }

    @Override
    public IColor getColor(String colorName){
        if(colorName.equalsIgnoreCase("Red")) return new Red();
        if(colorName.equalsIgnoreCase("Green")) return new Green();
        if(colorName.equalsIgnoreCase("Blue")) return new Blue();
        else return null;
    }
}
