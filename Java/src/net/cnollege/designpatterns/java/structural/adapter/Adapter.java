package net.cnollege.designpatterns.java.structural.adapter;

/**
 * Created by mugen on 1/11/17.
 */
public class Adapter extends Source implements Target {
    @Override
    public void sayHello() {
        super.printMessage("Hello!");
    }
}
