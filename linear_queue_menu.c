#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = 0, rear = -1;

void enqueue() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);
    queue[++rear] = value;
    printf("Element inserted.\n");
}

void dequeue() {
    if (front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front++]);
}

void search() {
    int key, found = 0;
    if (front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = front; i <= rear; i++) {
        if (queue[i] == key) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found!\n");
}

void display() {
    if (front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: search(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
