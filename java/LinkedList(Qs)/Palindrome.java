// Java program to check if a string is palindrome in linked list
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

    // Get Middle
    public Node getMiddle() {
        Node hare = head;
        Node turtle = head;
        while (hare.next != null && hare.next.next != null) {
            hare = hare.next.next;
            turtle = turtle.next;
        }
        return turtle;
    }

    // Reverse
    public Node reverse(Node newHead) {
        Node prev = null;
        Node curr = newHead;

        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Check Palindrome
    public boolean isPalindrome() {
        if (head == null || head.next == null) {
            return true;
        }

        Node mid = getMiddle();
        Node secStart = reverse(mid.next);

        Node firStart = head;

        while (secStart != null) {
            if (secStart.data != firStart.data) {
                return false;
            }

            firStart = firStart.next;
            secStart = secStart.next;
        }
        return true;
    }
}

public class Palindrome {
    public static void main(String[] args) {
        LL list = new LL();
        list.addLast("1");
        list.addLast("2");
        list.addLast("1");
        list.printList();
        boolean res = list.isPalindrome();
        if (res == true) {
            System.out.println("Palindrome");
        } else {
            System.out.println("Not Palindrome");
        }
    }
}
