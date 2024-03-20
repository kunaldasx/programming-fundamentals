// C program to find out whether a student is pass or fail
#include <stdio.h>

int main()
{
    int physics, chemistry, math;

    printf("Enter physics marks\n");
    scanf("%d", &physics);

    printf("Enter Chemistry marks\n");
    scanf("%d", &chemistry);

    printf("Enter math marks\n");
    scanf("%d", &math);

    float total = (physics + math + chemistry) / 3;
    if ((total < 40) || physics < 33 || math < 33 || chemistry < 33)
    {
        printf("Percentage: %f\nFail****\n", total);
    }
    else
    {
        printf("Percentage: %f\nPass****\n", total);
    }
    return 0;
}