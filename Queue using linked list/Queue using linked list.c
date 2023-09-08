#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define the Queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    newNode->data = item;
    newNode->next = NULL;
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d to the queue.\n", item);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        struct Node* temp = queue->front;
        int item = temp->data;
        queue->front = queue->front->next;
        free(temp);
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = queue->front;
        printf("Queue elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = createQueue();

    int choice, item;
    while (1) {
        printf("\nQUEUE OPERATION MENU\n");
        printf("1 --> ENQUEUE\n");
        printf("2 --> DEQUEUE\n");
        printf("3 --> isEmpty\n");
        printf("4 --> DISPLAY\n");
        printf("5 --> EXIT\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;

            case 2:
                item = dequeue(queue);
                if (item != -1) {
                    printf("Dequeued element: %d\n", item);
                }
                break;

            case 3:
                if (isEmpty(queue)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;

            case 4:
                display(queue);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

