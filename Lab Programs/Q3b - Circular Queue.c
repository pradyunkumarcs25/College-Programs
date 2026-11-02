#include <stdio.h>
#define SIZE 3

int queue[SIZE];
int front = -1;
int rear = -1;

void insert()
{
    int n;
    if(front == (rear+1)%SIZE)
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
    rear = (rear + 1)%SIZE;
    queue[rear] = n;
}

void delete()
{
    int n;
    if(front == -1)
    {
        printf("Queue Underflow");
        return;
    }
    n = queue[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else{
    front = (front + 1)%SIZE;
    }
    printf("Deleted element: %d",n);
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty");
        return;
    }
    printf("Queue elements:\n");
    for(i=front;i!=rear;i = (i+1)%SIZE)
    {
        printf("%d\n",queue[i]);
    }
    printf("%d",queue[i]);
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
