// Binary Search using recursion

import java.util.Scanner;

public class BinarySearch {
    public static void binarySearch(int arr[], int si, int ei, int num) {
        if (si > ei) {
            System.out.println("The number is not present in the list!");
            return;
        }
        int mid = (si + ei) / 2;
        if (arr[mid] == num) {
            System.out.println("The number is present at index: " + mid);
            return;
        }
        if (arr[mid] > num) {
            binarySearch(arr, si, mid - 1, num);
        }
        if (arr[mid] < num) {
            binarySearch(arr, mid + 1, ei, num);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the Array: ");
        int size = sc.nextInt();
        System.out.println("Enter the elements:");
        int arr[] = new int[10];
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.print("Enter the search item: ");
        int num = sc.nextInt();

        binarySearch(arr, 0, size - 1, num);
        sc.close();
    }
}
