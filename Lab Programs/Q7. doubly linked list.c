#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

typedef struct node* Node;
Node head = NULL;
int counter = 0;

Node generateNode()
{
    Node n = (Node)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("No memory to allocate\n");
    }
    return n;
}

void insertLeft(int data, int pos)
{
    if (head == NULL)
    {
        if (pos != 1)
        {
            printf("List is empty. Use position 1 for the first node.\n");
            return;
        }
        Node temp = generateNode();
        if (temp == NULL) return;
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
        counter++;
        return;
    }

    if (pos < 1 || pos > counter)
    {
        printf("Invalid position\n");
        return;
    }

    Node temp = generateNode();
    if (temp == NULL) return;
    temp->data = data;

    // Special case: inserting to the left of head (pos == 1)
    if (pos == 1)
    {
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
        counter++;
        return;
    }

    // Inserting before any other node
    Node cur = head;
    for (int i = 1; i < pos; i++)
    {
        cur = cur->next;
    }
    Node t = cur->prev;
    t->next = temp;
    temp->prev = t;
    temp->next = cur;
    cur->prev = temp;
    counter++;
}

void deleteNode(int pos)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (pos < 1 || pos > counter)
    {
        printf("Invalid position\n");
        return;
    }

    Node cur = head;
    for (int i = 1; i < pos; i++)
    {
        cur = cur->next;
    }

    printf("Deleted value: %d\n", cur->data);

    // Deleting the head node
    if (cur == head)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    // Deleting a middle or last node
    else
    {
        cur->prev->next = cur->next;
        if (cur->next != NULL)
        {
            cur->next->prev = cur->prev;
        }
    }

    free(cur);
    counter--;
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data, pos;
    printf("1. insert_left\n2. delete_node\n3. display list\n");
    for (;;)
    {
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter position: ");
            scanf("%d", &pos);
            printf("Enter data: ");
            scanf("%d", &data);
            insertLeft(data, pos);
            break;

        case 2:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteNode(pos);
            break;

        case 3:
            display();
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
