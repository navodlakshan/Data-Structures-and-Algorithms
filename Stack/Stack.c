#include <stdio.h>
#define MAX_SIZE 5

struct stack{
    int stk[MAX_SIZE];
    int top;
};

struct stack s;

void push(int item) {
    if (s.top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
    }else {
        s.top++;
        s.stk[s.top] = item;
        printf("Element %d pushed to the stack.\n", item);
    }
}

int pop() {
    if (s.top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }else {
        int item = s.stk[s.top];
        s.top--;
        printf("Element %d popped from the stack.\n", item);
        return item;
    }
}

int isEmpty() {
    return (s.top == -1);
}

int isFull() {
    return (s.top == MAX_SIZE -1);
}

int peek() {
    if (s.top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }else {
        return s.stk[s.top];
    }
}

void display() {
    if (s.top == -1) {
        printf("Stack is empty,\n");
    }else {
        printf("Stack elements: \n");
        for(int i=s.top; i >=0; i--) {
            printf("%d\n", s.stk[i]);
        }
    }
}
int main() {
    s.top = -1;

    int choice, item;
    while (1) {
        printf("\nSTACK OPERATION MENU\n");
        printf("1 --> PUSH\n");
        printf("2 --> POP\n");
        printf("3 --> isEmpty\n");
        printf("4 --> isFull\n");
        printf("5 --> peek\n");
        printf("6 --> DISPLAY\n");
        printf("7 --> EXIT\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item = pop();
                if (item != -1) {
                    printf("Popped element: %d\n", item);
                }
                break;

            case 3:
                if (isEmpty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 4:
                if (isFull()) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;

            case 5:
                item = peek();
                if (item != -1) {
                    printf("Top element: %d\n", item);
                }
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}