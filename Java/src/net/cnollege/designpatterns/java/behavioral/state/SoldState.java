package net.cnollege.designpatterns.java.behavioral.state;

/**
 * Created by mugen on 1/9/17.
 */
public class SoldState implements State {
    GumballMachine gumballMachine;

    public SoldState(GumballMachine gumballMachine) {
        this.gumballMachine = gumballMachine;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Please wait, a gumBall is already on its way!");
    }

    @Override
    public void ejectQuarter() {
        System.out.println("Sorry, you turned the crank. Gumball is on it's way!");
    }

    @Override
    public void turnCrank() {
        System.out.println("Turning twice won't give you another 'free' gumball!");
    }

    @Override
    public void dispense() {
        gumballMachine.releaseBall();
        if (gumballMachine.getCount() > 0) {
            gumballMachine.setState(gumballMachine.getNoQuarterState());
        } else {
            System.out.println("Opps! out of Gumballs!");
            gumballMachine.setState(gumballMachine.getSoldOutState());
        }
    }
}
