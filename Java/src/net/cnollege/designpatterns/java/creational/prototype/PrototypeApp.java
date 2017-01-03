package net.cnollege.designpatterns.java.creational.prototype;

/**
 * Created by mugen on 1/2/2017.
 */
public class PrototypeApp {
    public static void main(String[] args) {
        ShapeCache.loadCache();
        Shape clonedCircle = ShapeCache.getShape("circle");
        System.out.println(" Shape retrieved : " + clonedCircle.getName());

        Shape clonedTriangle = ShapeCache.getShape("triangle");
        System.out.println(" Shape retrieved : " + clonedTriangle.getName());

        Shape clonedRectangle = ShapeCache.getShape("rectangle");
        System.out.println(" Shape retrieved : " + clonedRectangle.getName());

    }
}
