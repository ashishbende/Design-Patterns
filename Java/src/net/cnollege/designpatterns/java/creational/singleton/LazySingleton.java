package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/1/2017.
 */
public class LazySingleton {
    // create bud don't instantiate singleton object
    private static LazySingleton singleton;
    // make constructor private
    private LazySingleton(){}

    // method to get singleton
    public static LazySingleton getSingleton(){
        if(singleton==null){
            // instantiate singleton
            singleton = new LazySingleton();
        }
        return singleton;
    }
}
