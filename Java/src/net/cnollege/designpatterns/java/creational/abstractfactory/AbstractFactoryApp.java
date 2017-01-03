package net.cnollege.designpatterns.java.creational.abstractfactory;

/**
 * Created by mugen on 1/2/2017.
 */
public class AbstractFactoryApp {
    public static void main(String[] args) {
        AbstractFactory shapeFactory = FactoryMaker.makeFactory("Shape");
        AbstractFactory colorFactory = FactoryMaker.makeFactory("Color");

        IShape circle = shapeFactory.getShape("Circle");
        IShape triangle = shapeFactory.getShape("triangle");
        IShape rectangle = shapeFactory.getShape("rectangle");

        IColor red = colorFactory.getColor("Red");
        IColor green = colorFactory.getColor("Green");
        IColor blue = colorFactory.getColor("Blue");

        circle.draw();red.fill();
        triangle.draw();green.fill();
        rectangle.draw();blue.fill();
    }
}
