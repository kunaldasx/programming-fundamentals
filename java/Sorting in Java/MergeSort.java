// Merge Sort

import java.util.Scanner;

class MergeSort {
    public static void conquer(int arr[], int si, int mid, int ei) {
        int merged[] = new int[ei - si + 1];
        int idx1 = si;
        int idx2 = mid + 1;
        int x = 0;

        // Comparing the two arrays and merging them in sorted order
        while (idx1 <= mid && idx2 <= ei) {
            if (arr[idx1] <= arr[idx2]) {
                merged[x++] = arr[idx1++];
            } else {
                merged[x++] = arr[idx2++];
            }
        }

        // If after merging, some elements are still left in the first array
        while (idx1 <= mid) {
            merged[x++] = arr[idx1++];
        }

        // If after merging, some elements are still left in the second array
        while (idx2 <= ei) {
            merged[x++] = arr[idx2++];
        }

        for (int i = 0, j = si; i < merged.length; i++, j++) {
            arr[j] = merged[i];
        }
    }

    public static void divide(int arr[], int si, int ei) {
        if (si >= ei) {
            return;
        }
        int mid = (si + ei) / 2;
        divide(arr, si, mid);
        divide(arr, mid + 1, ei);
        conquer(arr, si, mid, ei);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[] = new int[10];
        System.out.print("Enter the size of the Array: ");
        int size = sc.nextInt();
        System.out.println("Enter the elements of the Array:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        divide(arr, 0, size - 1);

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        sc.close();
    }
}