#include <stdio.h>
typedef struct time
{
    int hour;
    int min;
    int sec;
} time;

void display(time t, int a)
{
    printf("Time %d is: %d:%d:%d\n", a, t.hour, t.min, t.sec);
}

int timecmp(time t1, time t2)
{
    // Comparison on the basis of hour
    if (t1.hour > t2.hour)
    {
        return 1;
    }
    if (t1.hour < t2.hour)
    {
        return -1;
    }
    // Comparison on the basis of minute
    if (t1.min > t2.min)
    {
        return 1;
    }
    if (t1.min < t2.min)
    {
        return -1;
    }
    // Comparison on the basis of second
    if (t1.sec > t2.sec)
    {
        return 1;
    }
    if (t1.sec < t2.sec)
    {
        return -1;
    }
    return 0;
}
int main()
{
    time t1 = {12, 25, 52};
    time t2 = {00, 36, 40};

    display(t1, 1);
    display(t2, 2);

    int i = timecmp(t1, t2);
    if (i == 1)
    {
        printf("Time 1 is greater");
    }
    else if (i == -1)
    {
        printf("Time 2 is greater");
    }
    else
    {
        printf("Both the times are equal");
    }

    return 0;
}