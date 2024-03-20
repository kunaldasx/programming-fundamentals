// Find the number of ways in which you can invite n people to a party, single or in pairs

import java.util.Scanner;

public class CallGuests {
    public static int callGuests(int n) {
        if (n <= 1) {
            return 1;
        }
        // Single // Pair
        return callGuests(n - 1) + (n - 1) * callGuests(n - 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter total number of people: ");
        int n = sc.nextInt();
        System.out.println("Total number of ways to invite them: " + callGuests(n));
        sc.close();
    }
}
