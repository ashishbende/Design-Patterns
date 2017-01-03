package net.cnollege.designpatterns.java.creational.prototype;

/**
 * Created by mugen on 1/2/2017.
 */
public class Triangle extends Shape {

    public Triangle() {
        shapeName = "Triangle";
    }

    @Override
    void draw() {
        System.out.println("Drawing Triangle ...");
    }
}
