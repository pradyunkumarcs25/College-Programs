#include <stdio.h>
#include <process.h>
int s[5];
int item;
int top = -1;

void push()
{
    if(top==4)
    {

        printf("Stack overflow\n");
        return;
    }
    top += 1;
    printf("Enter item to insert: ");
    scanf("%d",&item);
    s[top] = item;
}

int pop()
{
    int item_deleted;
    if(top == -1)
    {
        printf("Stack underflow\n");
        return 0;
    }
    item_deleted = s[top];
    top -= 1;
    return item_deleted;
}

void display()
{

if(top == -1)
{
    printf("Stack is empty\n");
}
    for(int i=top; i>=0; i--)
    {
        printf("%d\n",s[i]);
    }
}

void main()
{
    int n;
    for(;;)
    {


    printf("1. push()\n2.pop()\n3.display()");
    printf("\nEnter choice: ");
    scanf("%d",&n);


      switch(n)
    {
    case 1:
        push();
        break;

    case 2:
        printf("%d\n",pop());
        break;

    case 3:
        display();
        break;

    default:
        printf("Invalid choice");
        break;
    }
    }

}

