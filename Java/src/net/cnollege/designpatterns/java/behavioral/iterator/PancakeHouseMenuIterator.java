package net.cnollege.designpatterns.java.behavioral.iterator;

import java.util.ArrayList;

/**
 * Created by mugen on 1/11/17.
 */
public class PancakeHouseMenuIterator implements Iterator {
    ArrayList<String> items;
    int position = 0;

    public PancakeHouseMenuIterator(ArrayList<String> menuItems) {
        items = menuItems;
    }

    public String next() {
        String item = items.get(position++);
        return item;
    }

    public boolean hasNext() {
        if (items.isEmpty() || items.size() == 0 || position >= items.size()) {
            return false;
        } else {
            return true;
        }
    }
}
