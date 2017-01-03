package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/1/2017.
 */
public class EagerSingleton {
    // create and instantiate singleton object
    private static final EagerSingleton singleton = new EagerSingleton();
    // make constructor private
    private EagerSingleton(){}
    // method to get singleton
    public static EagerSingleton getSingleton(){
        return singleton;
    }

}
