/* slice() is a function to slice a string. It changes the original string such that it is now the
sliced string. Taking m and n as the start and ending position for slice*/
#include <stdio.h>
void slice(char *st, int m, int n)
{
    int i = 0;
    while ((m + i) < n) // while(i<n) this will exactly till the nth position
    {
        st[i] = st[i + m];
        i++;
    }
    st[i] = '\0';
}
int main()
{

    char st[100];
    printf("Enter any word: \n");
    fgets(st, 100, stdin); // gets(st);
    int a, b;
    printf("Enter the start point for slice: \n");
    scanf("%d", &a);
    printf("Enter the end point for slice: \n");
    scanf("%d", &b);
    slice(st, a, b);
    printf("%s", st);
    return 0;
}