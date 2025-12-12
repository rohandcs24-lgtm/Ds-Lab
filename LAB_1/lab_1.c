#include <stdio.h>
#include <stdlib.h>

int stack[3];
int size = 5;
int top = -1;

void push(int val){
    if(top == size - 1){
        printf("Stack is already full (OVERFLOW)\n");
    } 
    else {
        top++;
        stack[top] = val;
        printf("Value %d successfully added into stack\n", val);
    }
}

int pop() {
    if(top == -1){
        printf("Stack is already empty (UNDERFLOW)\n");
        return -1; 
    } 
    else {
        int val = stack[top];
        top--;
        printf("Value %d successfully popped from stack\n", val);
        return val;  
    }
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
    } 
    else {
        printf("Elements of stack are:\n");
        for (int i = 0; i <= top; i++){
            printf("%d\n", stack[i]);
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\nEnter 1 for PUSH\n2 for POP\n3 for DISPLAY\n4 to EXIT\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: {
                int value;
                printf("Enter the value to PUSH: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}



