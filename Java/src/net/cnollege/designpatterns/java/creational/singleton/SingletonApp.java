package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/2/2017.
 */
public class SingletonApp {
    public static void main(String[] args) {
        EagerSingleton eagerSingleton = EagerSingleton.getSingleton();
        LazySingleton lazySingleton = LazySingleton.getSingleton();
        EnumPresident enumPresident = EnumPresident.INSTANCE;
    }
}
