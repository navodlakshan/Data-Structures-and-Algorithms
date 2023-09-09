#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global head pointer to the linked list

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
void create() {
    int data;
    struct Node* newNode;
    char ch;

    do {
        printf("Enter data for the new node: ");
        scanf("%d", &data);

        newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("Node added to the linked list.\n");

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

// Function to display the linked list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insert_begin() {
    int data;
    printf("Enter data for the new node: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;

    printf("Node inserted at the beginning.\n");
}

// Function to insert a node in the middle (after a specific value)
void insert_middle() {
    int data, value;
    printf("Enter data for the new node: ");
    scanf("%d", &data);

    printf("Enter the value after which you want to insert: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the linked list.\n");
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted after %d.\n", value);
    }
}

// Function to insert a node at the end
void insert_end() {
    int data;
    printf("Enter data for the new node: ");
    scanf("%d", &data);

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted at the end.\n");
}

// Function to delete a node from the beginning
void delete_begin() {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from the beginning.\n");
}

// Function to delete a node in the middle (by value)
void delete_middle() {
    int value;
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the value you want to delete: ");
    scanf("%d", &value);

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in the linked list. Nothing deleted.\n");
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        printf("Node with value %d deleted.\n", value);
    }
}

// Function to delete a node from the end
void delete_end() {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }
    free(temp);

    printf("Node deleted from the end.\n");
}

int main() {
    int choice;

    do {
        printf("\nLINKED LIST OPERATIONS\n");
        printf("1 --> Create a linked list\n");
        printf("2 --> Display the linked list\n");
        printf("3 --> Insert at the beginning\n");
        printf("4 --> Insert in the middle\n");
        printf("5 --> Insert at the end\n");
        printf("6 --> Delete from the beginning\n");
        printf("7 --> Delete from the middle\n");
        printf("8 --> Delete from the end\n");
        printf("9 --> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_middle();
                break;
            case 5:
                insert_end();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_middle();
                break;
            case 8:
                delete_end();
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}
