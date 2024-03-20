// Print factorial of a number

public class Factorial {
    public static int printFactorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return n * printFactorial(n - 1);
    }

    // public static void printFactorial(int n, int fact) {
    // if (n == 0) {
    // System.out.println(fact);
    // return;
    // }
    // fact *= n;
    // printFactorial(n - 1, fact);
    // }

    public static void main(String[] args) {
        int n = 5;
        int fact = printFactorial(n);
        System.out.println(fact);
    }
}
