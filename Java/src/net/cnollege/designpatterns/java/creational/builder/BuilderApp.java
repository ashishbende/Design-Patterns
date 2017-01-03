package net.cnollege.designpatterns.java.creational.builder;

/**
 * Created by mugen on 1/2/2017.
 */
public class BuilderApp {
    public static void main(String[] args) {
        MealBuilder mealBuilder = new MealBuilder();

        Meal vegMeal = mealBuilder.PrepVegMeal();
        Meal nonVegMeal = mealBuilder.PrepNonVegMeal();

        vegMeal.showItems();
        System.out.println("Total Cost:  " + vegMeal.getCost());
        nonVegMeal.showItems();
        System.out.println("Total Cost:  " + nonVegMeal.getCost());

    }
}
