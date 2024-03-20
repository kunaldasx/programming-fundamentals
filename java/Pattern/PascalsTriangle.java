// Pascal's Triangle 
//     1 
//    1 1    
//   1 2 1   
//  1 3 3 1  
// 1 4 6 4 1 
public class PascalsTriangle {
    public static void main(String[] args) {
        int n = 5, number;
        for (int i = 0; i < n; i++) {

            // Spaces
            for (int j = 1; j < (n - i); j++) {
                System.out.print(" ");
            }

            // Stars
            number = 1;
            for (int j = 0; j <= i; j++) {
                System.out.print(number + " ");
                number = number * (i - j) / (j + 1);
            }
            System.out.println();
        }
    }
}
