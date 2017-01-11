package net.cnollege.designpatterns.java.behavioral.iterator;

/**
 * Created by mugen on 1/11/17.
 */
public class DinerMenu implements Menu {
    static final int MAX_ITEMS = 6;
    int numberOfItems = 0;
    String[] menuItems;

    public DinerMenu() {
        menuItems = new String[MAX_ITEMS];
        addItem("Soup");
        addItem("Veg Burger");
        addItem("Pasta");
        addItem("Steamed Veggies & Brown Rice");
    }

    public void addItem(String item) {
        if (numberOfItems >= MAX_ITEMS) {
            System.out.println("Sorry, Menu is full. Can't add anything at this time");
        } else {
            menuItems[numberOfItems++] = item;
        }
    }

    public String[] getMenu() {
        return menuItems;
    }


    public Iterator createIterator() {
        return new DinerMenuIterator(menuItems);
    }

    public String toString() {
        return "Diner Menu";
    }
}
