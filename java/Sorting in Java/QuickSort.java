// Quick Sort

import java.util.Scanner;

public class QuickSort {
    public static int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int idx = low - 1;
        for (int i = low; i < high; i++) {
            if (arr[i] < pivot) {
                idx++;
                // Swap
                int temp = arr[idx];
                arr[idx] = arr[i];
                arr[i] = temp;
            }
        }
        // Swap with pivot
        idx++;
        int temp = arr[idx];
        arr[idx] = arr[high];
        arr[high] = temp;

        return idx;
    }

    public static void quickSort(int arr[], int low, int high) {
        if (low >= high) {
            return;
        }
        int pidx = partition(arr, low, high);
        quickSort(arr, low, pidx - 1);
        quickSort(arr, pidx + 1, high);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("How many numbers?");
        int size = scan.nextInt();
        int arr[] = new int[10];
        for (int i = 0; i < size; i++) {
            arr[i] = scan.nextInt();
        }

        quickSort(arr, 0, size - 1);

        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        scan.close();
    }
}
