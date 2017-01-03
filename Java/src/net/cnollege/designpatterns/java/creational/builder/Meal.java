package net.cnollege.designpatterns.java.creational.builder;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mugen on 1/2/2017.
 */
public class Meal {
    private List<IItem> items = new ArrayList<IItem>();

    public void showItems() {
        System.out.println("-------- MEAL -----------");
        for (IItem item : items) {
            System.out.println("Item  : " + item.name());
            System.out.println("Packing  : " + item.packing().pack());
            System.out.println("Cost  : " + item.price());
        }
        System.out.println("-------- MEAL -----------");
    }

    public void addItem(IItem item) {
        items.add(item);
    }

    public float getCost() {
        float cost = 0.0f;
        for (IItem item : items) {
            cost += item.price();
        }
        return cost;
    }
}
