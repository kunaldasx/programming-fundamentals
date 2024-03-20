// Java program to swap nodes in pairs in a singly linked list

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

    // Swapping in pairs
    public void swap() {
        if (head == null || head.next == null) {
            return;
        }

        Node first = head;
        head = head.next; // 2nd node of the main ll will be the new head of the swapped ll
        while (true) {
            Node second = first.next;
            Node temp = second.next;

            // swap
            second.next = first;
            if (temp == null || temp.next == null) {
                first.next = temp;
                break;
            }
            // update
            first.next = temp.next;
            first = temp;
        }
    }
}

class SwapPairs {
    public static void main(String[] args) {
        LL list = new LL();
        list.addLast("1");
        list.addLast("2");
        list.addLast("3");
        list.addLast("4");
        list.addLast("5");
        list.addLast("6");
        list.printList();
        list.swap();
        list.printList();
    }
}
