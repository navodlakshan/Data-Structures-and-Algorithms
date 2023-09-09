#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the circular queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the circular queue is full
int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

// Function to enqueue an element into the circular queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = item;
    printf("Enqueued %d to the queue.\n", item);
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (front == rear) {
        printf("Dequeued %d from the queue.\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued %d from the queue.\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to get the front element of the circular queue
int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

// Function to display the elements in the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nCIRCULAR QUEUE OPERATIONS\n");
        printf("1 --> Enqueue\n");
        printf("2 --> Dequeue\n");
        printf("3 --> Peek\n");
        printf("4 --> Display\n");
        printf("5 --> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                item = peek();
                if (item != -1) {
                    printf("Front element: %d\n", item);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
