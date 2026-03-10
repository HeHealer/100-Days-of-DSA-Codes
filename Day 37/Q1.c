/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <string.h>
#define MAX 1000
int heap[MAX], size = 0;
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void insert(int x) {
    heap[size] = x;
    int i = size++;
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", heap[0]);
    heap[0] = heap[--size];
    int i = 0;
    while (2 * i + 1 < size) {
        int j = 2 * i + 1;
        if (j + 1 < size && heap[j + 1] < heap[j]) j++;
        if (heap[i] <= heap[j]) break;
        swap(&heap[i], &heap[j]);
        i = j;
    }
}
void peek() {
    if (size == 0) printf("-1\n");
    else printf("%d\n", heap[0]);
}
int main() {
    int n, x;
    char op[10];
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }
    return 0;
}