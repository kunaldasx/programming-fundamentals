import java.util.Scanner;
//import java.lang.*;

class PrintCommon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number: ");
        String str = sc.nextLine();
        String used = new String();
        int count;

        for (int i = 0; i < str.length(); i++) {
            count = 0;
            char ch = str.charAt(i);
            if (used.indexOf(ch) != -1) { // if (used.contains("str.charAt(i)")) {
                continue;
            } else {
                used += ch;
                for (int j = i + 1; j < str.length(); j++) {
                    if (str.charAt(i) == str.charAt(j)) {
                        count++;
                    }
                }
                if (count != 0) {
                    count++;
                }
                for (int j = 0; j < count; j++) {
                    System.out.print(str.charAt(i));
                }
                System.out.print(" ");
            }
        }
        sc.close();
    }
}