package net.cnollege.designpatterns.java.behavioral.observer;

/**
 * Created by mugen on 1/7/17.
 */
public class WeatherStation {
    public static void main(String[] args) {
        WeatherData weatherData = new WeatherData();
        CurrentConditionsDisplay currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
        ForecastDisplay forecastDisplay = new ForecastDisplay(weatherData);

        weatherData.setMeasurements(60, 65, 30.4f);
        weatherData.setMeasurements(82, 85, 28.4f);
        weatherData.setMeasurements(76, 95, 29.7f);

    }
}
