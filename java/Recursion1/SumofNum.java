// Print the sum of first N natural numbers

public class SumofNum {
    public static void printSum(int n, int sum) {
        if (n == 0) {
            System.out.print(sum);
            return;
        }
        sum += n;
        printSum(n - 1, sum);
    }

    public static void main(String[] args) {
        int n = 5, sum = 0;
        printSum(n, sum);
    }
}
