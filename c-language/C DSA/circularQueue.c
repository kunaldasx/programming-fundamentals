#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int f = -1, r = -1;

void enqueue(int queue[])
{
    int data;
    if (f == (r + 1) % SIZE)
    {
        printf("Queue is overflow\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &data);
    r = (r + 1) % SIZE;
    queue[r] = data;
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

    if (f == r)
    {
        printf("Deque element is %d\n", queue[f]);
        f = r = -1;
        return;
    }

    printf("Deque element is %d\n", queue[f]);
    f = (f + 1) % SIZE;
}

void display(int queue[])
{
    int i;
    if (f == -1)
    {
        printf("Queue is Underflow\n");
        return;
    }

    for (i = f; i != r; i = (i + 1) % SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main()
{
    int queue[SIZE], ch;
    while (1)
    {
        printf("Enter 1 for Enqueue\nEnter 2 for Deque\nEnter 3 for Display\nEnter 4 to Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(queue);
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