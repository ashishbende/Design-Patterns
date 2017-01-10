package net.cnollege.designpatterns.java.behavioral.state;

/**
 * Created by mugen on 1/9/17.
 */
public class HasQuarterState implements State {
    GumballMachine gumballMachine;

    public HasQuarterState(GumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Machine already has a quarter! Can't insert another.");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("Quarter returned!");
        gumballMachine.setState(gumballMachine.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("You turned the crank...");
        gumballMachine.setState(gumballMachine.getSoldState());
    }

    @Override
    public void dispense() {

    }
}
