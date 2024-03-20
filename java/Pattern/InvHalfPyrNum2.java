// Inverted Half Pyramid of Numbers (2)
// 1 1 1 1 
// 2 2 2   
// 3 3     
// 4      
public class InvHalfPyrNum2 {
    public static void main(String[] args) {
        int n = 4;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i + 1; j++) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
    }
}
