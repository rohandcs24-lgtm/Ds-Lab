#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack[top--];
}

int getPrecedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}


int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int i = 0, j = 0;
    char item, x;

    printf("Enter a valid parenthesized infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0;

    push('('); 
    strcat(infix, ")"); 

    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isalnum(item)) { 
            postfix[j] = item;
            j++;
        } else if (item == ')') {
            x = pop();
            while (x != '(') {
                postfix[j] = x;
                j++;
                x = pop();
            }
        } else { 
            
            while (getPrecedence(stack[top]) >= getPrecedence(item)) {
                postfix[j] = pop();
                j++;
            }
            push(item);
        }
        i++;
        item = infix[i];
    }

    postfix[j] = '\0';

    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}