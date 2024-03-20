// Java Program to delete all data greater than 25 from a linkedlist.

//import java.util.LinkedList;
import java.util.Scanner;

class LL {

    Node head;

    public class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Add Last
    public void addLast(int data) {
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

    // Delete greater than 25
    public void delete() {
        Node prev = null;
        Node curr = head;
        while (curr != null) {
            if (curr.data > 25) {
                prev.next = curr.next;
                curr.next = null;
                curr = prev.next;
            } else {
                prev = curr;
                curr = curr.next;
            }
        }
    }
}

class Delete {
    public static void main(String[] args) {
        // LinkedList<Integer> list = new LinkedList<>();
        LL list = new LL();
        Scanner sc = new Scanner(System.in);
        int i;
        do {
            System.out.print("Enter a data: ");
            i = sc.nextInt();
            if (i == 0) {
                break;
            } else {
                list.addLast(i);
            }
        } while (true);

        list.printList();
        list.delete();
        list.printList();

        sc.close();

        // System.out.println(list);

        // for (int j = 0; j < list.size(); j++) {
        // for (int k = 0; k < list.size(); k++) {
        // if (list.get(k) > 25) {
        // list.remove(k);
        // }
        // }
        // }
        // System.out.println("The New LinkedList is :");
        // System.out.println(list);
        // sc.close();
    }
}
