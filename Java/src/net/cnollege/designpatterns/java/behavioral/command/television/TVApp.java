package net.cnollege.designpatterns.java.behavioral.command.television;

/**
 * Created by mugen on 1/14/2017.
 *  client application
 */

public class TVApp {
    public static void main(String[] args) {

        // get TV
        ElectronicDevice device = TVRemote.getDevice();

        // get Command
        TurnTVOn onCommand = new TurnTVOn(device);

        // get button
        DeviceButton onPressed = new DeviceButton(onCommand);
        // execute action
        onPressed.pressButton();

        // get action/command
        TurnTVVolumeUp volumeUpCommand = new TurnTVVolumeUp(device);

        DeviceButton onVolumeUp = new DeviceButton(volumeUpCommand);
        onVolumeUp.pressButton();
        onVolumeUp.pressButton();
        onVolumeUp.pressButton();

    }
}
