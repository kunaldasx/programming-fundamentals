// Java program to implement the different types of operations on ArrayyList

import java.util.ArrayList;
import java.util.Collections;

class Array_List {
    public static void main(String args[]) {
        // Declaring an ArrayList of different Types
        ArrayList<Integer> list = new ArrayList<>();
        // ArrayList<String> list2 = new ArrayList<String>();
        // ArrayList<Boolean> list3 = new ArrayList<Boolean>();

        // Add elements
        list.add(1);
        list.add(3);
        list.add(0);
        list.add(4);
        list.add(5);
        // Print all the elements of ArrayList
        System.out.println(list);

        // Get an element
        int element = list.get(0); // 0 is the index
        System.out.println(element);

        // Add Element at a specific index
        list.add(1, 2);// 1 is the index and 2 is the element to be added
        System.out.println(list);

        // Set Element at a specific index
        list.set(3, 7);
        System.out.println(list);

        // Delete Element from an index
        list.remove(3);
        System.out.println(list);

        // Size of list
        int size = list.size();
        System.out.println(size);

        // Loops/Iterate on list
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }
        System.out.println();

        // Sorting the list
        list.add(0);
        Collections.sort(list);
        System.out.println(list);
    }
}