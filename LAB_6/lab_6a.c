#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct node **start, int value) {
    struct node *newNode = createNode(value);
    if (*start == NULL) {
        *start = newNode;
        return;
    }
    struct node *temp = *start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct node *start) {
    struct node *i, *j;
    int temp;

    if (start == NULL) return;

    for (i = start; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse(struct node **start) {
    struct node *prev = NULL, *current = *start, *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *start = prev;
}

struct node* concatenate(struct node *head1, struct node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n==== Singly Linked List Operations ====\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display Lists\n");
        printf("4. Sort List 1\n");
        printf("5. Reverse List 1\n");
        printf("6. Concatenate List 1 & List 2\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;

            case 4:
                sortList(list1);
                printf("List 1 sorted.\n");
                break;

            case 5:
                reverse(&list1);
                printf("List 1 reversed.\n");
                break;

            case 6:
                list1 = concatenate(list1, list2);
                printf("Lists concatenated into List 1.\n");
                list2 = NULL;
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
