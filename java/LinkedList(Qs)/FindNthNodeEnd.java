// Java Program to Find the nth term from the end in a linked list and remove it.
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

    // Add First
    public void addFirst(String data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Add Last
    public void addLast(String data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node currNode = head;
        while (currNode.next != null) {
            currNode = currNode.next;
        }
        currNode.next = newNode;
    }

    // Print List
    public void printList() {
        Node currNode = head;
        while (currNode != null) {
            System.out.print(currNode.data + "->");
            currNode = currNode.next;
        }
        System.out.println("null");
    }

    // Remove First
    public void removeFirst() {
        if (head == null) {
            System.out.println("List is Empty");
        }
        head = head.next;
    }

    // Remove Last
    public void removeLast() {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        if (head.next == null) {
            head = null;
            return;
        }

        Node currNode = head;
        Node lastNode = head.next;
        while (lastNode.next != null) {
            currNode = currNode.next;
            lastNode = lastNode.next;
        }
        currNode.next = null;
    }

    // Find Nth Node from end
    public void deleteNode(int n) {
        if (head.next == null) {
            head = null;
        }

        int size = 0;
        Node temp = head;
        while (temp != null) {
            temp = temp.next;
            size++;
        }

        // Removing size th node
        if (n == size) {
            head = head.next;
        }

        // Find Previous node
        int ptf = size - n - 1; // n-1 th node

        Node prevNode = head;
        int i = 1;
        while (i != ptf) {
            prevNode = prevNode.next;
            i++;
        }
        prevNode.next = prevNode.next.next;
    }
}

public class FindNthNodeEnd {
    public static void main(String[] args) {
        LL list = new LL();
        list.addLast("1");
        list.addLast("2");
        list.addLast("3");
        list.addLast("4");
        list.addLast("5");
        list.printList();
        list.deleteNode(2);
        list.printList();
    }
}
