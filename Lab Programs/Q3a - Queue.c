#include <stdio.h>
#define SIZE 4

int queue[SIZE];
int front = -1;
int rear = -1;

void insert()
{
    int n;
    if(rear == SIZE - 1)
    {
        printf("Queue Overflow");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d",&n);
    if(front == -1)
    {
        front = front+1;
    }
    rear += 1;
    queue[rear] = n;
}

void delete()
{
    int n;
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow");
        return;
    }
    n = queue[front];
    front = front + 1;
    printf("Deleted element: %d",n);
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue elements:\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
}

void main()
{
    int n;
    for(;;)
    {
        printf("\n1.insert\n2.delete\n3.display\n");
        printf("Choice: ");
        scanf("%d",&n);

            switch(n)
            {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            default:
                printf("\nInvalid choice");
                break;
            }
    }

}
