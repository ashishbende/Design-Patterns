package net.cnollege.designpatterns.java.behavioral.command.television;

/**
 * Created by mugen on 1/14/2017.
 *
 *  This is an invoker, it has no knowledge about the what device or command is being used
 */
public class DeviceButton {
    Command command;

    public DeviceButton(Command newCommand){
        this.command = newCommand;
    }

    public void pressButton(){
        command.execute();
    }
}
