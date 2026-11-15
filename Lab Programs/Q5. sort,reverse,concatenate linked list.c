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
    }
    return n;
}

Node insertNode(int data, Node head) {
    Node temp = generateNode();
    if (temp == NULL) return head;
    temp->data = data;
    temp->link = head;
    return temp;
}

Node sort(Node head) {
    Node i, j;
    for (i = head; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

Node reverse(Node head) {
    Node prev = NULL;
    Node current = head;
    Node next = NULL;
    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node concatenate(Node head1, Node head2) {
    if (head1 == NULL && head2 == NULL) {
        printf("Both lists are empty\n");
        return NULL;
    }
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node temp = head1;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = head2;
    return head1;
}

void display(Node head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->link;
    }
    printf("NULL\n");
}

int main() {
    Node head1 = NULL;
    Node head2 = NULL;

    head1 = insertNode(10, head1);
    head1 = insertNode(5, head1);
    head1 = insertNode(17, head1);

    head2 = insertNode(19, head2);
    head2 = insertNode(2, head2);
    head2 = insertNode(23, head2);

    printf("Linked list 1:\n");
    display(head1);
    printf("\n");

    printf("Linked list 2:\n");
    display(head2);
    printf("\n");

    head1 = sort(head1);
    printf("First sorted list:\n");
    display(head1);
    printf("\n");

    head2 = sort(head2);
    printf("Second sorted list:\n");
    display(head2);
    printf("\n");

    head1 = reverse(head1);
    printf("First reversed list:\n");
    display(head1);
    printf("\n");

    head2 = reverse(head2);
    printf("Second reversed list:\n");
    display(head2);
    printf("\n");

    Node concat = concatenate(head1, head2);
    printf("Concatenated list:\n");
    display(concat);

    return 0;
}
