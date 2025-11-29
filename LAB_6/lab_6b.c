#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};



struct node *stackTop = NULL;


void push(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = stackTop;
    stackTop = newNode;
    printf("Pushed %d onto stack.\n", value);
}

void pop() {
    if (stackTop == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    struct node *temp = stackTop;
    printf("Popped %d from stack.\n", temp->data);
    stackTop = stackTop->next;
    free(temp);
}

void displayStack() {
    if (stackTop == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node *temp = stackTop;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into queue.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued %d from queue.\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL; 
    }
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node *temp = front;
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n===== Singly Linked List: Stack & Queue Simulation =====\n");
        printf("1. PUSH (Stack)\n");
        printf("2. POP (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. ENQUEUE (Queue)\n");
        printf("5. DEQUEUE (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Enter value to ENQUEUE: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 5:
                dequeue();
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
