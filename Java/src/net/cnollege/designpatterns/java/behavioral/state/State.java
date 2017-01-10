package net.cnollege.designpatterns.java.behavioral.state;

/**
 * Created by mugen on 1/9/17.
 */
public interface State {
    public void insertQuarter();

    public void ejectQuarter();

    public void turnCrank();

    public void dispense();
}
