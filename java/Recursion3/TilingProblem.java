// Tiling Problem
// Size of Floor = m x n
// Size of Tile = 1 x n

import java.util.Scanner;

public class TilingProblem {
    public static int placeTiles(int m, int n) {
        if (m == n) {
            return 2;
        }
        if (m < n) {
            return 1;
        }
        // Vertical Placement //Horizontal Placement
        return placeTiles(m - n, n) + placeTiles(m - 1, n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the order of the floor: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println("Number of ways: " + placeTiles(m, n));
        sc.close();
    }
}
