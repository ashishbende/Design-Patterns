package net.cnollege.designpatterns.java.creational.abstractfactory;

/**
 * Created by mugen on 1/2/2017.
 */
public class Circle implements IShape {
    @Override
    public void draw(){
        System.out.println("Drawing Circle");
    }
}
