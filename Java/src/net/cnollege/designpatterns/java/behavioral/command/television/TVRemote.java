package net.cnollege.designpatterns.java.behavioral.command.television;

/**
 * Created by mugen on 1/14/2017.
 */
public class TVRemote {

    public static ElectronicDevice getDevice(){
        return new Television();
    }
}
