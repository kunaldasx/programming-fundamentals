// C program to compute the difference of each element in an array from the average
#include <stdio.h>
float average(int arr[], int n)
{
    int sum = 0;
    float avg;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    avg = (float)sum / n;
    return avg;
}
void find_diff(int arr[], int n, float avg)
{
    float diff[10];
    for (int i = 0; i < n; i++)
    {
        diff[i] = avg - arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("The difference for %dth element: %.2f\n", i + 1, diff[i]);
    }
}
int main()
{
    int ar[10], size, i;
    float avg;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &ar[i]);
    }
    avg = average(ar, size);
    printf("Average: %.2f\n", avg);
    find_diff(ar, size, avg);
    return 0;
}