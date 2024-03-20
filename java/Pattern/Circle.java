public class Circle {
    public static void main(String[] args) {
        int n = 6;
        double dist;
        for (int i = 0; i <= 2 * n; i++) {
            for (int j = 0; j <= 2 * n; j++) {
                dist = Math.sqrt((i - n) * (i - n) + (j - n) * (j - n));

                if (dist < n + 0.5 && dist > n - 0.5) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }
}
