package net.cnollege.designpatterns.java.creational.prototype;

/**
 * Created by mugen on 1/2/2017.
 */
public abstract class Shape implements Cloneable {
    protected String shapeName;

    abstract void draw();

    public String getName() {
        return shapeName;
    }

    public Object clone() {
        Object clone = null;
        try {
            clone = super.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return clone;
    }

}
