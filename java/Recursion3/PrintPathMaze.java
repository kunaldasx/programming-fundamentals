// Count Path Maze
// count all possible paths to travel from index (0,0) to the last index(m-1, n-1)

import java.util.Scanner;

public class PrintPathMaze {
    public static int printpaths(int i, int j, int m, int n) {
        if (i == m - 1 || j == n - 1) {
            return 1;
        }
        return printpaths(i + 1, j, m, n) + printpaths(i, j + 1, m, n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter order of the Maze: ");
        int m = sc.nextInt();
        int n = sc.nextInt();
        System.out.println("Number of Ways: " + printpaths(0, 0, m, n));
        sc.close();
    }
}
