package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/1/2017.
 */
public class EagerSingleton {
    private static final EagerSingleton singleton = new EagerSingleton();
    private EagerSingleton(){}

    public static EagerSingleton getSingleton(){
        return singleton;
    }

}
