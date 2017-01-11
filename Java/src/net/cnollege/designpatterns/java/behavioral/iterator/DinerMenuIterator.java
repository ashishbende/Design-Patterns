package net.cnollege.designpatterns.java.behavioral.iterator;

/**
 * Created by mugen on 1/11/17.
 */
public class DinerMenuIterator implements Iterator {
    String[] items;
    int position = 0;

    public DinerMenuIterator(String[] menuItems) {
        this.items = menuItems;
    }

    public String next() {
        String menuItem = items[position++];
        return menuItem;
    }

    public boolean hasNext() {
        if (position >= items.length || items[position] == null) {
            return false;
        } else {
            return true;
        }
    }
}
