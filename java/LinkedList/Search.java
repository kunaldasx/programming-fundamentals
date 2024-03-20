// Searching for a specific element

//import java.util.LinkedList;

class LL {

    Node head;

    public class Node {
        String data;
        Node next;

        Node(String data) {
            this.data = data;
            this.next = null;
        }
    }

    // Add Last
    public void addLast(String data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node lastNode = head;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
        }

        lastNode.next = newNode;
    }

    // Print List
    public void printList() {
        Node currNode = head;

        while (currNode != null) {
            System.out.print(currNode.data + " -> ");
            currNode = currNode.next;
        }

        System.out.println("null");
    }

    // Search
    public void search(String n) {
        Node currNode = head;
        int i = 0;
        while (currNode != null) {
            if (currNode.data == n) {
                System.out.println("Index = " + i);
                return;
            }
            currNode = currNode.next;
            i++;
        }
        System.out.println("Element not found");
    }
}

class Search {
    public static void main(String[] args) {
        LL list = new LL();
        list.addLast("1");
        list.addLast("5");
        list.addLast("7");
        list.addLast("3");
        list.addLast("8");
        list.addLast("2");
        list.addLast("3");

        // for (int i = 0; i < l i++) {
        // if (list.get(i) == 7) {
        // System.out.println("Index of 7 is " + i);
        // }
        // }

        list.printList();
        list.search("7");
    }
}
