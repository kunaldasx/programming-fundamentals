// Java Program to Detect and Remove a Cycle/loop in a Linked List  
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

    // Detect Cycles
    public Node hascycle() {
        Node fast = head;
        Node slow = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (fast == slow) {
                return slow;
            }
        }
        // deleteCycle(slow); slow is the meeting point
        return null;

    }

    // Deleting a Cycle
    public void deleteCycle(Node start) { // start is the Begining from the meeting point
        Node curr = head; // begining from head
        while (curr != start) { // the point at which they both meet is the starting point of the loop
            curr = curr.next;
            start = start.next;
        }
        curr.next = null; // Deleting the loop
    }
}

public class DetectCycle {
    public static void main(String[] args) {
        LL list = new LL();
        list.addLast("1");
        list.addLast("2");
        list.addLast("3");
        list.addLast("4");
        list.addLast("5");
        list.addLast("6");
        list.addLast("7");

        // Creating the loop
        list.head.next.next.next.next.next.next = list.head.next.next.next; // Loop starts from 4

        LL.Node res = list.hascycle();
        if (res == null) {
            System.out.println("Cycle not Found");
        } else {
            System.out.println("Cycle Detected");
        }

        list.deleteCycle(res);
        list.printList();
    }
}
