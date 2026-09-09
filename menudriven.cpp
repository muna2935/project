#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Insert element into queue
void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = item;
    printf("%d inserted into queue.\n", item);
}

// Delete element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d deleted from queue.\n", queue[front]);
    front++;

    if (front > rear)
        front = rear = -1;
}

// Display queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Peek front element
void peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front element is: %d\n", queue[front]);
}

int main() {
    int choice, item;

    do {
        printf("\n----- LINEAR QUEUE MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}