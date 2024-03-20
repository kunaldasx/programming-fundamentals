// Linked List
#include <stdio.h>
#include <stdlib.h>
int size = 0;
struct node
{
    int data;
    struct node *add;
};
struct node *head = NULL;

// Add First
void addFirst(int val)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("memory not assigned");
        return;
    }
    else
    {
        temp->data = val;
        temp->add = head;
        head = temp;
        size++;
    }
}

// Add Last
void addLast(int val)
{

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("memory not assigned");
        return;
    }
    else
    {
        temp->data = val;
        size++;
        if (head == NULL)
        {
            temp->add = (head);
            head = temp;
        }
        else
        {
            struct node *temp1 = (head);
            while (temp1->add != NULL)
            {
                temp1 = temp1->add;
            }
            temp->add = NULL;
            temp1->add = temp;
        }
    }
}

// Add at a particular index
void add(int index, int val)
{
    if (index > size || index < 0)
    {
        printf("Invalid Input");
        return;
    }

    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("memory not assigned");
        return;
    }
    newNode->data = val;
    size++;
    if (index == 0 || head == NULL)
    {
        newNode->add = head;
        head = newNode;
        return;
    }
    struct node *curr = head;
    for (int i = 1; i < size; i++)
    {
        if (i == index)
        {
            newNode->add = curr->add;
            curr->add = newNode;
            break;
        }
        curr = curr->add;
    }
}

// Display
void display()
{
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d -> ", curr->data);
        curr = curr->add;
    }
    printf("NULL\n");
}

int main()
{
    int ch, index, val;
    do
    {
        printf("Enter your choice\nPress 1 to Add First\nPress 2 to Add Last\nPress 3 to Add at an Index\nPress 4 to Display\nPress 0 to Stop\n: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &val);
            addFirst(val);
            break;

        case 2:
            printf("Enter the data: ");
            scanf("%d", &val);
            addLast(val);
            break;

        case 3:
            printf("Enter the index: ");
            scanf("%d", &index);
            printf("Enter the data: ");
            scanf("%d", &val);
            add(index, val);
            break;

        case 4:
            display();
            break;

        default:
            printf("Exited!");
        }
    } while (ch);

    return 0;
}
