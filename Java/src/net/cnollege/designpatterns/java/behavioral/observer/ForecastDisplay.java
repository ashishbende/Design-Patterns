package net.cnollege.designpatterns.java.behavioral.observer;

/**
 * Created by mugen on 1/7/17.
 */
public class ForecastDisplay implements Observer, DisplayElement {

    private float temperature;
    private float humidity;
    private Subject weather;

    public ForecastDisplay(Subject weather) {
        this.weather = weather;
        weather.registerObserver(this);
    }

    @Override
    public void update(float temp, float humidity, float pressure) {
        // some dumb forcast calculations.
        temp++;
        humidity++;
        pressure--;
    }

    @Override
    public void display() {
        System.out.println("Improving weather conditions : " + temperature + "F degrees and humidity %" + humidity);

    }
}
