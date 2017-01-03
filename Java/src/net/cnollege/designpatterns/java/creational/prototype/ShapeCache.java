package net.cnollege.designpatterns.java.creational.prototype;

import java.util.Hashtable;

/**
 * Created by mugen on 1/2/2017.
 */
public class ShapeCache {
    private static Hashtable<String, Shape> shapeDB = new Hashtable<String, Shape>();

    public static Shape getShape(String shapeName) {
        Shape cachedShape = shapeDB.get(shapeName);
        return (Shape) cachedShape.clone();
    }

    public static void loadCache() {
        Circle circle = new Circle();
        Rectangle rectangle = new Rectangle();
        Triangle triangle = new Triangle();
        shapeDB.put("circle", circle);
        shapeDB.put("triangle", triangle);
        shapeDB.put("rectangle", rectangle);
    }
}
