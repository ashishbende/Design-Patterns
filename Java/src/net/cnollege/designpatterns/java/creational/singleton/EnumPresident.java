package net.cnollege.designpatterns.java.creational.singleton;

/**
 * Created by mugen on 1/1/2017.
 */
public enum EnumPresident {
    INSTANCE;
    private int age;
    private String country;

    public int getAge(){
        return  age;
    }
    public String getCountry(){
        return country;
    }g
}
