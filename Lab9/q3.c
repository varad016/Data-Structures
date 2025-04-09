#include <stdio.h>
#define SIZE 5

struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

void initQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct CircularQueue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

int isEmpty(struct CircularQueue *q) {
    return q->front == -1;
}

void enqueue(struct CircularQueue *q, int item) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = item;
    printf("Enqueued: %d\n", item);
}

void dequeue(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Dequeued: %d\n", q->items[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
}

void display(struct CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 60);
    display(&q);
    
    return 0;
}

