#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

typedef struct Node* Node;

Node first = NULL;
int counter = 0;

Node generateNode() {
    Node n = (Node)malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Out of memory to allocate\n");
        return NULL;
    }
    counter++;
    return n;
}

void insert_first(int data) {
    Node temp = generateNode();
    if (temp == NULL) return;
    temp->data = data;
    temp->link = first;
    first = temp;
}

void insert_rear(int data) {
    Node temp = generateNode();
    if (temp == NULL) return;
    temp->data = data;
    temp->link = NULL;

    if (first == NULL) {
        first = temp;
        return;
    }
    Node current = first;
    while (current->link != NULL) {
        current = current->link;
    }
    current->link = temp;
}

void insert_pos(int data, int pos) {
    if (pos < 1 || pos > counter + 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insert_first(data);
        return;
    }

    Node temp = generateNode();
    if (temp == NULL) return;
    temp->data = data;

    Node cur = first;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->link;
    }
    temp->link = cur->link;
    cur->link = temp;
}

void display() {
    if (first == NULL) {
        printf("Linked List is empty\n");
    } else {
        Node cur = first;
        while (cur != NULL) {
            printf("%d -> ", cur->data);
            cur = cur->link;
        }
        printf("NULL\n");
    }
}

void delete_first() {
    if (first == NULL) {
        printf("List is empty\n");
    } else {
        Node temp = first;
        printf("Deleted element: %d\n", temp->data);
        first = first->link;
        free(temp);
        counter--;
    }
}

void delete_last() {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    if (first->link == NULL) {
        printf("Deleted element: %d\n", first->data);
        free(first);
        first = NULL;
        counter--;
        return;
    }
    Node cur = first;
    Node prev = NULL;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted element: %d\n", cur->data);
    prev->link = NULL;
    free(cur);
    counter--;
}

void delete_pos(int pos) {
    if (pos < 1 || pos > counter) {
        printf("Invalid position\n");
        return;
    }
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        delete_first();
        return;
    }

    Node cur = first;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->link;
    }
    Node temp = cur->link;
    cur->link = temp->link;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    counter--;
}

int main() {
    for (;;) {
        int n;
        printf("\n1.Insert first\n2.Insert rear\n3.Insert anywhere\n4.Delete first\n5.Delete last\n6.Delete anywhere\n7.Display\n8.Exit\n");
        printf("Choice: ");
        if (scanf("%d", &n) != 1) break;

        switch (n) {
            case 1: {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insert_first(data);
                break;
            }
            case 2: {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                insert_rear(data);
                break;
            }
            case 3: {
                int data, pos;
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_pos(data, pos);
                break;
            }
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6: {
                int pos;
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            }
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
