#include <stdio.h>
typedef struct timestamp
{
    int year;
    int month;
    int date;
    int hour;
    int min;
    int sec;
} timestamp;

void display(timestamp v, int a)
{
    printf("Timestamp %d is: %d/%d/%d %02d:%02d:%02d\n", a, v.year, v.month, v.date, v.hour, v.min, v.sec);
}

int timestampcmp(timestamp v1, timestamp v2)
{
    // Comparison on the basis of year
    if (v1.year > v2.year)
    {
        return 1;
    }
    else if (v1.year < v2.year)
    {
        return -1;
    }
    // Comparison on the basis of month
    else if (v1.month > v2.month)
    {
        return 1;
    }
    else if (v1.month < v2.month)
    {
        return -1;
    }
    // Comparison on the basis of date
    else if (v1.date > v2.date)
    {
        return 1;
    }
    else if (v1.date < v2.date)
    {
        return -1;
    }
    // Comparison on the basis of hour
    else if (v1.hour > v2.hour)
    {
        return 1;
    }
    else if (v1.hour < v2.hour)
    {
        return -1;
    }
    // Comparison the basis of minute
    else if (v1.min > v2.min)
    {
        return 1;
    }
    else if (v1.min < v2.min)
    {
        return -1;
    }
    // Comparison on the basis of second
    else if (v1.sec > v2.sec)
    {
        return 1;
    }
    else if (v1.sec < v2.sec)
    {
        return -1;
    }
    return 0;
}
int main()
{
    timestamp v1 = {2001, 10, 25, 00, 07, 05};
    timestamp v2 = {1994, 04, 20, 05, 52, 36};
    display(v1, 1);
    display(v2, 2);

    int i = timestampcmp(v1, v2);
    if (i == 1)
    {
        printf("Timestamp 1 is greater");
    }
    else if (i == -1)
    {
        printf("Timestamp 2 is greater");
    }
    else
    {
        printf("Both the timestamps are equal");
    }
    return 0;
}