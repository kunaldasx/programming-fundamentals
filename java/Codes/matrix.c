#include<stdio.h>

int main(){
    int n, arr[45][45];
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
        
    }

    printf("\nThe result matrix:\n");
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i][i] < 0)
        {
            arr[i][i]=0;
        }
        else{
            arr[i][i]=1;
        }    
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}    