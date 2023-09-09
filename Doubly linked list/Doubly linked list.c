#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to check if the list is empty
int is_empty() {
    return (head == NULL);
}

// Function to insert a node at the beginning
void insert_begin(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert a node at the end
void insert_end(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to insert a node in the middle (after a specific value)
void insert_middle(int data, int afterValue) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    while (temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list. Node not inserted.\n");
    } else {
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node from the beginning
void delete_begin() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Function to delete a node from the middle (by value)
void delete_middle(int data) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the list. Nothing deleted.\n");
    } else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// Function to delete a node from the end
void delete_end() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

// Function to reverse the doubly linked list
void reverse() {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

// Function to display the doubly linked list in forward direction
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }
    printf("Doubly linked list (forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, afterValue;

    while (1) {
        printf("\nDOUBLY LINKED LIST OPERATIONS\n");
        printf("1 --> Insert at the beginning\n");
        printf("2 --> Insert at the end\n");
        printf("3 --> Insert in the middle\n");
        printf("4 --> Delete from the beginning\n");
        printf("5 --> Delete from the middle\n");
        printf("6 --> Delete from the end\n");
        printf("7 --> Display\n");
        printf("8 --> Reverse\n");
        printf("9 --> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insert_begin(data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insert_end(data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the value after which you want to insert: ");
                scanf("%d", &afterValue);
                insert_middle(data, afterValue);
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                printf("Enter the value you want to delete: ");
                scanf("%d", &data);
                delete_middle(data);
                break;

            case 6:
                delete_end();
                break;

            case 7:
                display();
                break;

            case 8:
                reverse();
                printf("Doubly linked list reversed.\n");
                break;

            case 9:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
