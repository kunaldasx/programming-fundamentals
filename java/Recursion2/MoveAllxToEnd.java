// Move all ‘x’ to the end of the string. - O(n)

public class MoveAllxToEnd {

    // to add all 'x' to the end of the string
    public static String addX(int count) {
        String newStr = "x";
        for (int i = 1; i < count; i++) {
            newStr += 'x';
        }
        return newStr;
    }

    public static String moveAllX(String str, int idx, int count) {
        if (idx == str.length()) {
            return addX(count);
        }
        if (str.charAt(idx) == 'x') {
            return moveAllX(str, idx + 1, count + 1);
        } else {
            String nextStr = moveAllX(str, idx + 1, count);
            return str.charAt(idx) + nextStr;
        }
    }

    public static void main(String args[]) {
        String str = "abcdefxghxixjxxxk";
        int count = 0;
        String newStr = moveAllX(str, 0, count);
        System.out.println(newStr);
    }
}
