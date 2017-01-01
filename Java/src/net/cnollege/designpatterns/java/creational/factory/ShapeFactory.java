package net.cnollege.designpatterns.java.creational.factory;

/**
 * Created by mugen on 1/1/2017.
 */
public class ShapeFactory {
    public Shape getShape(String shapeType) {

        if (shapeType.equalsIgnoreCase("Circle")) {
            return new Circle();
        }

        if (shapeType.equalsIgnoreCase("Square")) {
            return new Square();
        }


        if (shapeType.equalsIgnoreCase("Rectangle")) {
            return new Rectangle();
        }

        return null;
    }
}
