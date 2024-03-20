// Print a string in reverse.

public class PrintStringinRev {
    public static String revString(String str) {
        if (str.length() == 1) {
            return str;
        }
        char currChar = str.charAt(0);
        String nextString = revString(str.substring(1));
        return nextString + currChar;
    }

    // public static void revString(String str, int index) {
    // if (index == 0) {
    // System.out.print(str.charAt(index));
    // return;
    // }
    // System.out.print(str.charAt(index));
    // revString(str, index - 1);
    // }

    public static void main(String args[]) {

        String str = "abcd";
        // revString(str, str.length() - 1);
        String reversed = revString(str);
        System.out.println(reversed);
    }
}
