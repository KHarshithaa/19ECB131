#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert at end
void insert_at_end(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Insert at beginning
void insert_at_beginning(struct Node** head, int data) {
    struct Node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Delete node by value
void delete_node(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

// Search node by value
int search(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key)
            return 1;
        head = head->next;
    }
    return 0;
}

// Print the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_beginning(&head, 5);
    insert_at_end(&head, 30);

    printf("Initial list:\n");
    display(head);

    printf("\nDeleting 20:\n");
    delete_node(&head, 20);
    display(head);

    int key = 10;
    if (search(head, key))
        printf("\n%d found in the list.\n", key);
    else
        printf("\n%d not found in the list.\n", key);

    return 0;
}
