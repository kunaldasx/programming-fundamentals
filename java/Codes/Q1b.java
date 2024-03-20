import java.util.Scanner;

class Q1b {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string");
        String str = sc.nextLine();
        int len = str.length();
        String str1 = new String();
        for (int i = len - 1; i >= 0; i--) {
            str1 = str1 + str.charAt(i);
        }
        if (str.equals(str1)) {
            System.out.println("Is Palindrome");
        } else {
            System.out.println("Is Not Palindrome");
        }
    }
}