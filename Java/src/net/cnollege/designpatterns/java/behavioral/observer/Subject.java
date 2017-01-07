package net.cnollege.designpatterns.java.behavioral.observer;

/**
 * Created by mugen on 1/7/17.
 */
public interface Subject {
    public void registerObserver(Observer o);

    public void removeObserver(Observer o);

    public void notifyObservers();
}
