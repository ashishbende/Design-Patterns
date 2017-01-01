package net.cnollege.designpatterns.java.creational.factory;

/**
 * Created by mugen on 1/1/2017.
 */
public class FactoryApp {
    public static void main(String[] args) {
        ShapeFactory buildMeShape = new ShapeFactory();
        Shape circle = buildMeShape.getShape("Circle");
        Shape square = buildMeShape.getShape("Square");
        Shape rectangle = buildMeShape.getShape("Rectangle");

        circle.draw();
        square.draw();
        rectangle.draw();

    }
}
