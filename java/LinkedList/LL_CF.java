
// Linked List using Collection Framework.
import java.util.LinkedList;

class LL_CF {
    public static void main(String args[]) {
        LinkedList<String> list = new LinkedList<String>();
        list.add("is"); // Writing just list.add adds the new node to the last by default
        list.add("a");
        list.addLast("list");
        list.addFirst("this");
        list.add(3, "linked");
        System.out.println(list);

        System.out.println(list.get(0));
        System.out.println(list.size());
        list.remove(3);
        list.removeFirst();
        list.removeLast();

        System.out.println(list);
    }
}
