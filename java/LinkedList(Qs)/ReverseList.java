// Program in java to reverse a linked list

class LL {
    Node head;
    private int size;

    LL() {
        size = 0;
    }

    public class Node {
        String data;
        Node next;

        Node(String data) {
            this.data = data;
            this.next = null;
            size++;
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

    // Insert Middle
    public void addMiddle(int index, String data) {
        if (index > size || index < 0) {
            System.out.println("Invalid index value");
            return;
        }

        Node newNode = new Node(data);
        if (head == null || index == 0) {
            newNode.next = head;
            head = newNode;
            return;
        }

        Node currNode = head;
        for (int i = 0; i < size; i++) {
            if (i == index - 1) {
                newNode.next = currNode.next;
                currNode.next = newNode;
                break;
            }
            currNode = currNode.next;
        }
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
        size--;
    }

    // Remove Last
    public void removeLast() {
        if (head == null) {
            System.out.println("List is Empty");
            return;
        }

        size--;
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

    // Get Size
    public int getSize() {
        return size;
    }

    // Reverse a list
    public void reverseList() {
        if (head == null || head.next == null) {
            return;
        }

        Node prevNode = head;
        Node currNode = head.next;
        while (currNode != null) {
            Node nextNode = currNode.next;
            currNode.next = prevNode;

            // Update
            prevNode = currNode;
            currNode = nextNode;
        }
        head.next = null;
        head = prevNode;
    }
}

public class ReverseList {
    public static void main(String[] args) {
        LL list = new LL();
        list.addLast("1");
        list.addLast("2");
        list.addLast("3");
        list.addLast("4");
        list.printList();
        list.reverseList();
        list.printList();
    }
}
