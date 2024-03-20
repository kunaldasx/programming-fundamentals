// Butterfly Pattern 
// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *
public class ButterflyPattern {
    public static void main(String[] args) {
        int n = 4;

        // Upper Half
        for (int i = 1; i <= n; i++) {
            // Left Stars
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }

            // Mid Spaces
            for (int j = 1; j <= 2 * (n - i); j++) {
                System.out.print(" ");
            }

            // Right Stars
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }

        // Lower Half
        for (int i = n; i >= 1; i--) {
            // Left Stars
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }

            // Mid Spaces
            for (int j = 1; j <= 2 * (n - i); j++) {
                System.out.print(" ");
            }

            // Right Stars
            for (int j = 1; j <= i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
