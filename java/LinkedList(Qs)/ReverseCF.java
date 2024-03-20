import java.util.LinkedList;
import java.util.Collections;

public class ReverseCF {
    public static void main(String[] args) {
        LinkedList<String> list = new LinkedList<>();

        list.add("1");
        list.add("2");
        list.add("3");
        list.add("4");
        list.add("5");

        Collections.reverse(list);
        System.out.print(list);
    }
}
