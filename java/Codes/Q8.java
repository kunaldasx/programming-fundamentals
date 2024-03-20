public class Q8 {
    public static void main(String[] args) {
        int n = 5, a = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                System.out.print((a++) + " ");
            }
            System.out.println();
        }
    }
}
