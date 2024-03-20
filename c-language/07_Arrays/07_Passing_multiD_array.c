// Create a 2D array by taking input from the user and write a display function to the content of this 2D array on the screen
#include <stdio.h>

// METHOD 1******************************************************************************
// void display(int marks[][5], int a, int b) // Here row is not compulsory but column is
// {
//     for (int i = 0; i < a; i++)
//     {
//         for (int j = 0; j < b; j++)
//         {
//             printf("The marks of student %d in subject %d is: %d\n", i + 1, j + 1, marks[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int n_student = 3, n_subject = 5;
//     int marks[3][5];

//     for (int i = 0; i < n_student; i++)
//     {
//         for (int j = 0; j < n_subject; j++)
//         {
//             printf("Enter the marks of student %d in subject %d: ", i + 1, j + 1);
//             scanf("%d", &marks[i][j]);
//         }
//         printf("\n");
//     }
//     display(marks, 3, 5);
//     return 0;
// }

// METHOD 2********************************
// void display(int (*ptr)[5], int a, int b)
// {
//     for (int i = 0; i < a; i++)
//     {
//         for (int j = 0; j < b; j++)
//         {
//             printf("The marks of student %d in subject %d is: %d\n", i + 1, j + 1, ptr[i][j]);
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int n_student = 3, n_subject = 5;
//     int marks[3][5];

//     for (int i = 0; i < n_student; i++)
//     {
//         for (int j = 0; j < n_subject; j++)
//         {
//             printf("Enter the marks of student %d in subject %d: ", i + 1, j + 1);
//             scanf("%d", &marks[i][j]);
//         }
//         printf("\n");
//     }
//     display(marks, 3, 5);
//     return 0;
// }

// METHOD 3***********************************
void display(int *ptr, int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("The marks of student %d in subject %d is: %d\n", i + 1, j + 1, *((ptr + i * b) + j));
        }
        printf("\n");
    }
}
int main()
{
    int n_student = 3, n_subject = 5;
    int marks[3][5];

    for (int i = 0; i < n_student; i++)
    {
        for (int j = 0; j < n_subject; j++)
        {
            printf("Enter the marks of student %d in subject %d: ", i + 1, j + 1);
            scanf("%d", &marks[i][j]);
        }
        printf("\n");
    }
    display((int *)marks, 3, 5); // Here we have to typecast the 2D array before
    return 0;                    // passing it to the function
}