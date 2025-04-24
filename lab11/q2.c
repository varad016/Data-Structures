#include <stdio.h>

#define N 50

int queue[N];

int start = -1, end = -1;

int enqueue (int value) {
    if (end >= N - 1) {
        printf("Queue overflow!!");
        return -1;
    }
    start = 0;
    queue[++end] = value;
}

int create (int i) {
    while (i != 0) {
        enqueue(i % 2);
        i = i / 2;
    }
}

void revert() {
    for (int i = 0; i <= (end - start) / 2; i++) {
        int temp = queue[start + i];
        queue[start + i] = queue[end - i];
        queue[end - i] = temp;
    }
}

int display () {
    if (start != -1) {
        while (start != end + 1) {
            printf("%d", queue[start]);
            start++;
        }
        printf("\n");
        start = -1;
        end = -1;
    } 
}

void main () {
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        create(i);
        revert();
        display();        
    }
}