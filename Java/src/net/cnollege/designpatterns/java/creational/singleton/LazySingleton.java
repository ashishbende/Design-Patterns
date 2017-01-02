package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/1/2017.
 */
public class LazySingleton {
    private static LazySingleton singleton;
    private LazySingleton(){}

    public static LazySingleton getSingleton(){
        if(singleton==null){
            singleton = new LazySingleton();
        }
        return singleton;
    }
}
