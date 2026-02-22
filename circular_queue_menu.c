#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue() {
    int value;
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("Element inserted.\n");
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void search() {
    int key, i;
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    i = front;
    while (1) {
        if (queue[i] == key) {
            printf("Element found at index %d\n", i);
            return;
        }
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("Element not found!\n");
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
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
