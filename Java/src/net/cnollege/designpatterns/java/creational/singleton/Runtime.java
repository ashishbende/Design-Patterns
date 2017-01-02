package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/1/2017.
 */
public class Runtime {
    private static Runtime currentRuntime = new Runtime();

    public static Runtime getRuntime() {
        return currentRuntime;
    }

    private Runtime() {}
}
