package net.cnollege.designpatterns.java.behavioral.state;

/**
 * Created by mugen on 1/9/17.
 */
public class SoldOutState implements State {

    GumballMachine gumballMachine;

    public SoldOutState(GumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("The machine is sold out! Cannot insert quarter");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("You can't eject, you haven't inserted a quarter yet!");
    }

    @Override
    public void turnCrank() {
        System.out.println("Sorry, no Gumballs at this time.");
    }

    @Override
    public void dispense() {
        System.out.println("No Gumballs to dispense!");
    }
}
