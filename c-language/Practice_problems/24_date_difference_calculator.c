#include <stdio.h>

int main()
{
    int d1, m1, y1, d2, m2, y2, i, m = 0, y = 0;
    printf("Enter date from(in format DD/MM/YYY): ");
    scanf("%d %d %d", &d1, &m1, &y1);
    printf("Enter date to  (in format DD/MM/YYY): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    // If Months and Years are same

    if (m1 == m2 && y1 == y2)
    {
        printf("Diff: %d days", (d2 - d1));
    }

    // If the Years are same

    else if (y1 == y2)
    {
        for (i = m1; i < m2; i++)
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                m = m + 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                m = m + 30;
                break;
            case 2:
                if (y1 % 400 == 0)
                {
                    m = m + 29;
                }
                else if (y1 % 100 == 0)
                {
                    m = m + 28;
                }
                else if (y1 % 4 == 0)
                {
                    m = m + 29;
                }
                else
                {
                    m = m + 28;
                }
                break;
            }
        }
        printf("Diff: %d", m + (d2 - d1));
    }

    // For distinct Months and Year

    else
    {
        for (i = m1; i < 13; i++)
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                m = m + 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                m = m + 30;
                break;
            case 2:
                if (y1 % 400 == 0)
                {
                    m = m + 29;
                }
                else if (y1 % 100 == 0)
                {
                    m = m + 28;
                }
                else if (y1 % 4 == 0)
                {
                    m = m + 29;
                }
                else
                {
                    m = m + 28;
                }
                break;
            }
        }
        for (i = 1; i < m2; i++)
        {
            switch (i)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                m = m + 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                m = m + 30;
                break;
            case 2:
                if (y1 % 400 == 0)
                {
                    m = m + 29;
                }
                else if (y1 % 100 == 0)
                {
                    m = m + 28;
                }
                else if (y1 % 4 == 0)
                {
                    m = m + 29;
                }
                else
                {
                    m = m + 28;
                }
                break;
            }
        }
        if ((y2 - y1) >= 2)
        {
            for (i = y1 + 1; i < y2; i++)
            {
                if (i % 400 == 0)
                {
                    y = y + 366;
                }
                else if (i % 100 == 0)
                {
                    y = y + 365;
                }
                else if (i % 4 == 0)
                {
                    y = y + 366;
                }
                else
                {
                    y = y + 365;
                }
            }
        }
        printf("Diff: %d", y + m + (d2 - d1));
    }
    return 0;
}