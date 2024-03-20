// Adding two binary numbers
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    char ans[45];
    int carry = 0, n = 0;

    while (num1 && num2)
    {
        // Two digits are zero
        if (num1 % 10 == 0 && num2 % 10 == 0)
        {
            ans[n++] = carry + '0';
            carry = 0;
        }

        // 1 & 0
        else if ((num1 % 10 == 0 && num2 % 10 == 1) || (num1 % 10 == 1 && num2 % 10 == 0))
        {
            if (carry == 1)
            {
                ans[n++] = 0 + '0';
                carry = 1;
            }
            else
            {
                ans[n++] = 1 + '0';
                carry = 0;
            }
        }

        // both digits are 1
        else
        {
            if (carry == 1)
            {
                ans[n++] = 1 + '0';
                carry = 1;
            }
            else
            {
                ans[n++] = 0 + '0';
                carry = 1;
            }
        }
        num1 /= 10;
        num2 /= 10;
    }

    // if num1 has more digits than num2
    while (num1)
    {
        if (carry == 1)
        {
            if (num1 % 10 == 1)
            {
                ans[n++] = 0 + '0';
                carry = 1;
            }
            else
            {
                ans[n++] = 1 + '0';
                carry = 0;
            }
        }
        else
        {
            ans[n++] = (num1 % 10) + '0';
        }
        num1 /= 10;
    }

    // if num1 has more digits than num1
    while (num2)
    {
        if (carry == 1)
        {
            if (num2 % 10 == 1)
            {
                ans[n++] = 0 + '0';
                carry = 1;
            }
            else
            {
                ans[n++] = 1 + '0';
                carry = 0;
            }
        }
        else
        {
            ans[n++] = (num2 % 10) + '0';
        }
        num2 /= 10;
    }

    // The remaining carry is added
    ans[n] = carry + '0';

    // char ans1[45];
    //  for (int i = 0; i < n; i++)
    //  {
    //      ans1[i] = ans[n - i];
    //  }

    for (int i = n; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}