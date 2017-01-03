package net.cnollege.designpatterns.java.creational.prototype;

/**
 * Created by mugen on 1/2/2017.
 */
public class Circle extends Shape {

    public Circle() {
        shapeName = "Circle";
    }

    @Override
    void draw() {
        System.out.println("Drawing Circle...");
    }
}
