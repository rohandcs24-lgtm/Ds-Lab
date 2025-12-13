#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void create() {
    int n, i, value;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

void insert_left() {
    int key, value;
    struct node *temp = head, *newnode;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter node value to insert to its left: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = temp->prev;
    newnode->next = temp;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
}

void delete_value() {
    int key;
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully\n");
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    do {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left of a Node\n");
        printf("3. Delete a Node by Value\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_value(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
