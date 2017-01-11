package net.cnollege.designpatterns.java.behavioral.iterator;

import java.util.ArrayList;

/**
 * Created by mugen on 1/11/17.
 */
public class PancakeHouseMenu implements Menu {
    ArrayList<String> menuItems;

    public PancakeHouseMenu() {
        menuItems = new ArrayList<>();
        addItem("Breakfast Pancake");
        addItem("Regular Pancake");
        addItem("Blueberry Pancake");
        addItem("Waffle");
        addItem("Coffee");
        addItem("Muffin");
    }

    public void addItem(String item) {
        menuItems.add(item);
    }

    public ArrayList<String> getMenuItems() {
        return menuItems;
    }

    @Override
    public Iterator createIterator() {
        return new PancakeHouseMenuIterator(menuItems);
    }

    @Override
    public String toString() {
        return "Pancake House Menu";
    }
}
