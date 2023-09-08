#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int front, rear, size;
    int arr[MAX_SIZE];
};

struct Queue q;

void initQueue() {
    q.front = q.rear = -1;
    q.size = 0;
}

int isEmpty() {
    return q.size == 0;
}

int isFull() {
    return q.size == MAX_SIZE;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    } else {
        if (isEmpty()) {
            q.front = q.rear = 0;
        } else {
            q.rear = (q.rear + 1) % MAX_SIZE;
        }
        q.arr[q.rear] = item;
        q.size++;
        printf("Enqueued %d to the queue.\n", item);
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int item = q.arr[q.front];
        if (q.front == q.rear) {
            q.front = q.rear = -1;
        } else {
            q.front = (q.front + 1) % MAX_SIZE;
        }
        q.size--;
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = q.front;
        while (1) {
            printf("%d ", q.arr[i]);
            if (i == q.rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    initQueue();

    int choice, item;
    while (1) {
        printf("\nQUEUE OPERATION MENU\n");
        printf("1 --> ENQUEUE\n");
        printf("2 --> DEQUEUE\n");
        printf("3 --> isEmpty\n");
        printf("4 --> isFull\n");
        printf("5 --> DISPLAY\n");
        printf("6 --> EXIT\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;

            case 3:
                if (isEmpty()) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 4:
                if (isFull()) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
