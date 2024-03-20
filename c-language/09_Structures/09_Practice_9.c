#include <stdio.h>
typedef struct date
{
    int date;
    int month;
    int year;
} date;
void display(date d, int a)
{
    printf("Date %d is: %d/%d/%d\n", a, d.date, d.month, d.year);
}
int datecmp(date d1, date d2)
{
    // Comparison on the basis of year
    if (d1.year > d2.year)
    {
        return 1;
    }
    if (d1.year < d2.year)
    {
        return -1;
    }
    // Comparison on the basis of month
    if (d1.month > d2.month)
    {
        return 1;
    }
    if (d1.month < d2.month)
    {
        return -1;
    }
    // Comparison on the basis of date
    if (d1.date > d2.date)
    {
        return 1;
    }
    if (d1.date < d2.date)
    {
        return -1;
    }
    return 0;
}
int main()
{
    date d1 = {25, 10, 2001};
    date d2 = {03, 03, 2003};
    display(d1, 1);
    display(d2, 2);
    int i = datecmp(d1, d2);

    if (i == 1)
    {
        printf("Date 1 is greater");
    }
    else if (i == -1)
    {
        printf("Date 2 is greater");
    }
    else
    {
        printf("Both the dates are equal");
    }

    return 0;
}