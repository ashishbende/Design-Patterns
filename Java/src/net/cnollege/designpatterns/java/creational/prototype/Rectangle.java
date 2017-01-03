package net.cnollege.designpatterns.java.creational.prototype;

/**
 * Created by mugen on 1/2/2017.
 */
public class Rectangle extends Shape {

    public Rectangle() {
        shapeName = "Rectangle";
    }

    @Override
    void draw() {
        System.out.println("Drawing Rectangle ...");
    }
}
