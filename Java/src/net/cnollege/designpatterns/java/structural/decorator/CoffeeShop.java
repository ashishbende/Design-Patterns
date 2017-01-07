package net.cnollege.designpatterns.java.structural.decorator;

/**
 * Created by mugen on 1/7/17.
 */
public class CoffeeShop {
    public static void main(String[] args) {
        Beverage beverage = new Espresso();
        Beverage beverage1 = new HouseBlend();
        System.out.println("Special : " + beverage.getDescription() + " | " + beverage.cost());
        System.out.println(beverage1.getDescription() + " | " + beverage1.cost());

        // adding condiments
        beverage = new Soy(beverage);
        beverage1 = new Milk(beverage1);
        System.out.println(beverage.getDescription() + " | " + beverage.cost());
        System.out.println(beverage1.getDescription() + " | " + beverage1.cost());
    }
}
