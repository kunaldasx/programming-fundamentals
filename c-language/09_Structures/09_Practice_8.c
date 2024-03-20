#include <stdio.h>

typedef struct complex
{
    float real;
    float img;
} comp;
void display(comp c, int i)
{
    printf("The real value of num %d: %f \n", i + 1, c.real);
    printf("The imaginary value of num %d: %f\n", i + 1, c.img);
}
int main()
{
    comp cnum[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter the real value of num %d: ", i + 1);
        scanf("%f", &cnum[i].real);

        printf("Enter the imaginary value of num %d: ", i + 1);
        scanf("%f", &cnum[i].img);
    }
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        display(cnum[i], i);
        printf("\n");
    }
    return 0;
}