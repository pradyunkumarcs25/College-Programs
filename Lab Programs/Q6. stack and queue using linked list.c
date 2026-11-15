#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

typedef struct node* Node;

Node generateNode() {
    Node n = (Node)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("No memory\n");
        return NULL;
    }
    n->link = NULL;
    return n;
}


Node top = NULL;

void stack_push(int data) {
    Node temp = generateNode();
    if (temp == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}

void stack_pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Node temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->link;
    free(temp);
}

void display_stack() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node cur = top;
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->link;
    }
}


Node front = NULL;
Node rear = NULL;

void enqueue(int data) {
    Node temp = generateNode();
    if (temp == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    temp->data = data;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    Node temp = front;
    printf("Deleted item: %d\n", temp->data);
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void display_queue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node cur = front;
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->link;
    }
}

int main() {
    int choice, data;

    for (;;) {
        printf("\n1. stack_push\n2. stack_pop\n3. display_stack\n");
        printf("4. enqueue\n5. dequeue\n6. display_queue\n7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                stack_push(data);
                break;
            case 2:
                stack_pop();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                display_queue();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
