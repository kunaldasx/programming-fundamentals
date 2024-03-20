// A C progarm containing a function which counts the number of positive integers in an array
#include <stdio.h>
int countPositive(int max[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (max[i] > 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int max[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    printf("The number of positive integers in the array are: %d", countPositive(max, 11));
    return 0;
}