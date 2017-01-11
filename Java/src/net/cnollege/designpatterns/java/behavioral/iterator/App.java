package net.cnollege.designpatterns.java.behavioral.iterator;

/**
 * Created by mugen on 1/11/17.
 */
public class App {

    public static void main(String[] args) {


        PancakeHouseMenu pancakeHouseMenu = new PancakeHouseMenu();
        DinerMenu dinerMenu = new DinerMenu();

        Iterator pancakeIterator = pancakeHouseMenu.createIterator();
        Iterator dinerIterator = dinerMenu.createIterator();
        System.out.println("\n----- Breakfast menu -----\n");
        printMenu(pancakeIterator);
        System.out.println("\n----- Lunch menu -----\n");
        printMenu(dinerIterator);
    }

    private static void printMenu(Iterator iterator) {
        while (iterator.hasNext()) {
            System.out.println((String) iterator.next());
        }
    }


}
