// Print the following star pattern.The number of lines in the pattern should be equal to the value
// entered by the user. The pattern looks like this for n = 4:

// *
// **
// ***
// ****

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of lines required: ");
    scanf("%d", &n);
    // Method 1
    //  Run this loop for n times
    for (int i = 0; i < n; i++)
    {
        // print (i+1) stars
        for (int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    // Method 2
    // for (int i = 0; i < n; i++)
    // {
    //     // print (i+1) stars
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (j <= i)
    //         {
    //             printf("*");
    //         }
    //         else
    //         {
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");
    // }
    return 0;
}