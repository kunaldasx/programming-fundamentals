#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int top = -1;

int isFull()
{
    if (top == SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int stack[], int data)
{
    if (isFull())
    {
        printf("Stack is full");
        return;
    }

    stack[++top] = data;
}

int pop(int stack[])
{
    int data;
    if (isEmpty())
    {
        printf("Stack is Empty");
    }
    else
    {
        data = stack[top--];
        return data;
    }
}

void display(int stack[])
{
    int i;
    if (isEmpty())
    {
        printf("Stack is Empty!");
        return;
    }

    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{
    int stack[SIZE], ch, data;
    printf("Enter the elements: ");
    while (1)
    {
        printf("Enter a Choice\nPress 1 for Push\nPress 2 for Pop\nPress 3 for display\nPress 4 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            push(stack, data);
            break;

        case 2:
            printf("Pop element : %d\n", pop(stack));
            break;

        case 3:
            display(stack);
            break;

        case 4:
            exit(0);

        default:
            printf("Enter a valid choice!");
            break;
        }
    }
    return 0;
}