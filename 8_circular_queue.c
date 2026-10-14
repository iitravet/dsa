#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void enqueue(char x) {
    if ((rear + 1) % MAX == front) { printf("Overflow\n"); return; }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("Inserted %c\n", x);
}

void dequeue() {
    if (front == -1) { printf("Underflow\n"); return; }
    printf("Deleted %c\n", queue[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    if (front == -1) { printf("Queue is Empty\n"); return; }
    int i = front;
    printf("Queue: ");
    while (i != rear) {
        printf("%c ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", queue[rear]);
}

int main() {
    enqueue('A'); enqueue('B'); display(); dequeue(); display();
    return 0;
}
