package net.cnollege.designpatterns.java.structural.adapter;

/**
 * Created by mugen on 1/11/17.
 */
public class ClientApp {
    public static void main(String[] args) {
        Target object = new Adapter();
        object.sayHello();
    }
}
