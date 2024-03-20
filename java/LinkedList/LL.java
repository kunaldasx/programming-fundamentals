// Linkded List
public class LL {

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

        Node lastNode = head;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
        }

        lastNode.next = newNode;
    }

    // Add Middle
    public void addMiddle(int index, String data) {
        if (index > size || index < 0) {
            System.out.println("Invalid Index Value");
            return;
        }
        size++;
        Node newNode = new Node(data);
        if (head == null || index == 0) {
            newNode.next = head;
            head = newNode;
            return;
        }
        Node currNode = head;
        int i = 0;
        // for (int i = 1; i < size; i++) {
        while (currNode != null) {
            if (i == index - 1) {
                // Node nextNode = currNode.next;
                newNode.next = currNode.next;
                currNode.next = newNode;
                break;
            }
            currNode = currNode.next;
            i++;
        }
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

    // Remove First
    public void removeFirst() {
        if (head == null) {
            System.out.println("Empty List, nothing to delete");
            return;
        }

        head = this.head.next;
        size--;
    }

    // Remove Last
    public void removeLast() {
        if (head == null) {
            System.out.println("Empty List, nothing to delete");
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

    public static void main(String args[]) {
        LL list = new LL();
        list.addFirst("is");
        list.addLast("a");
        list.addLast("list");
        list.printList();

        // list.addFirst("this");
        // list.printList();
        // System.out.println(list.getSize());

        list.addMiddle(3, "linked");
        // list.printList();

        // list.removeFirst();
        // list.printList();

        // list.removeLast();
        // list.printList();
        System.out.println(list.getSize());
    }
}
