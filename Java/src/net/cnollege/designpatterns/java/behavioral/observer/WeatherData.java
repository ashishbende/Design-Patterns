package net.cnollege.designpatterns.java.behavioral.observer;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mugen on 1/7/17.
 */
public class WeatherData implements Subject {
    private List<Observer> observerList;
    private float temp;
    private float humidity;
    private float pressure;


    public WeatherData() {
        observerList = new ArrayList<Observer>();
    }

    @Override
    public void registerObserver(Observer o) {
        observerList.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        int i = observerList.indexOf(o);
        if (i >= 0) {
            observerList.remove(i);
        }
    }

    @Override
    public void notifyObservers() {
        for (int i = 0; i < observerList.size(); i++) {
            Observer observer = (Observer) observerList.get(i);
            observer.update(temp, humidity, pressure);
        }
    }

    public void setMeasurements(float temp, float humidity, float pressure) {
        this.temp = temp;
        this.humidity = humidity;
        this.pressure = pressure;
        measurementChanged();
    }

    public void measurementChanged() {
        notifyObservers();
    }

    public float getTemp() {
        return temp;
    }

    public void setTemp(float temp) {
        this.temp = temp;
    }

    public float getHumidity() {
        return humidity;
    }

    public void setHumidity(float humidity) {
        this.humidity = humidity;
    }

    public float getPressure() {
        return pressure;
    }

    public void setPressure(float pressure) {
        this.pressure = pressure;
    }

}
