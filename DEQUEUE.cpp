#include <stdio.h>
#define SIZE 10
int deque[SIZE];
int front = -1, rear = -1;
// Check if the Dequeue is empty
int isEmpty()
{
    return (front == -1);
}
// Check if the Dequeue is full
int isFull()
{
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}
// Insert an element at the front
void insertFront(int item)
{
    if (isFull())
    {
        printf("Dequeue is full! Cannot insert at front.\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }
    deque[front] = item;
    printf("%d inserted at the front.\n", item);
}

// Insert an element at the rear
void insertRear(int item)
{
    if (isFull())
    {
        printf("Dequeue is full! Cannot insert at rear.\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    deque[rear] = item;
    printf("%d inserted at the rear.\n", item);
}

// Delete an element from the front
void deleteFront()
{
    if (isEmpty())
    {
        printf("Dequeue is empty! Cannot delete from front.\n");
        return;
    }
    printf("%d deleted from the front.\n", deque[front]);
    if (front == rear)
    {
        front = rear = -1; // Reset to empty
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Delete an element from the rear
void deleteRear()
{
    if (isEmpty())
    {
        printf("Dequeue is empty! Cannot delete from rear.\n");
        return;
    }
    printf("%d deleted from the rear.\n", deque[rear]);
    if (front == rear)
    {
        front = rear = -1; // Reset to empty
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

// Display the elements of the Dequeue
void display()
{
    if (isEmpty())
    {
        printf("Dequeue is empty.\n");
        return;
    }
    printf("Dequeue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main()
{
    int choice, item;

    while (1)
    {
        printf("\nDequeue Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the item to insert at front: ");
            scanf("%d", &item);
            insertFront(item);
            break;
        case 2:
            printf("Enter the item to insert at rear: ");
            scanf("%d", &item);
            insertRear(item);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}