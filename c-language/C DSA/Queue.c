#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int f = -1, r = -1;

void enqueue(int queue[], int data)
{
    if (r == SIZE - 1)
    {
        printf("Queue is overflow\n");
        return;
    }
    queue[++r] = data;
    if (f == -1)
    {
        f++;
    }
}
void deque(int queue[])
{
    if (f == -1)
    {
        printf("Queue is Underflow\n");
        return;
    }

    printf("Deque element is %d\n", queue[f++]);
    if (f > r)
    {
        f = r = -1;
    }
}

void display(int queue[])
{
    if (f == -1)
    {
        printf("Queue is Underflow\n");
        return;
    }

    for (int i = f; i <= r; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int queue[SIZE], ch, data;
    while (1)
    {
        printf("Enter 1 for Enqueue\nEnter 2 for Deque\nEnter 3 for Display\nEnter 4 to Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;

        case 2:
            deque(queue);
            break;

        case 3:
            display(queue);
            break;

        case 4:
            exit(0);

        default:
            break;
        }
    }
}