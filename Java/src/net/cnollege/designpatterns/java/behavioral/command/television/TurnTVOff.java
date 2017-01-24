package net.cnollege.designpatterns.java.behavioral.command.television;

/**
 * Created by mugen on 1/14/2017.
 */
public class TurnTVOff implements Command {
    ElectronicDevice device;

    public TurnTVOff(ElectronicDevice device){
        this.device = device;
    }

    @Override
    public void execute() {
        device.off();
    }
}
