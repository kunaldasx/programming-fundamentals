#include <stdio.h>
#include <string.h>
typedef struct bankAccount
{
    int accNo;
    char name[10];
    float balance;
} bank;

int main()
{
    bank a1, a2;
    bank *ptr;
    ptr = &a1;

    strcpy(ptr->name, "Kunal");
    ptr->accNo = 100;
    ptr->balance = 500000;

    bank *ptr2;
    ptr2 = &a2;
    strcpy(ptr2->name, "Mukesh");
    ptr2->accNo = 101;
    ptr2->balance = 300000;

    printf("Account number: %d\n", ptr->accNo);
    printf("Account holder name: %s\n", ptr->name);
    printf("Account Balance: %.3f\n\n  ", ptr->balance);

    printf("Account number: %d\n", ptr2->accNo);
    printf("Account holder name: %s\n", ptr2->name);
    printf("Account Balance: %.3f\n", ptr2->balance);
    return 0;
}