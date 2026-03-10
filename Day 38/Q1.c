/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;
typedef struct {
    Node *head, *tail;
    int size;
} Deque;
void init(Deque *d) {
    d->head = d->tail = NULL;
    d->size = 0;
}
void push_front(Deque *d, int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->prev = NULL;
    n->next = d->head;
    if (d->head) d->head->prev = n;
    else d->tail = n;
    d->head = n;
    d->size++;
}
void push_back(Deque *d, int val) {
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    n->prev = d->tail;
    if (d->tail) d->tail->next = n;
    else d->head = n;
    d->tail = n;
    d->size++;
}
int pop_front(Deque *d) {
    if (!d->head) return -1;
    Node *t = d->head;
    int v = t->data;
    d->head = d->head->next;
    if (d->head) d->head->prev = NULL;
    else d->tail = NULL;
    free(t);
    d->size--;
    return v;
}
int pop_back(Deque *d) {
    if (!d->tail) return -1;
    Node *t = d->tail;
    int v = t->data;
    d->tail = d->tail->prev;
    if (d->tail) d->tail->next = NULL;
    else d->head = NULL;
    free(t);
    d->size--;
    return v;
}
void clear(Deque *d) {
    while (d->head) pop_front(d);
}
int main() {
    Deque d;
    init(&d);
    push_back(&d, 10);
    push_front(&d, 20);
    printf("Front: %d, Back: %d, Size: %d\n", d.head->data, d.tail->data, d.size);
    pop_back(&d);
    printf("New Back: %d\n", d.tail->data);
    clear(&d);
    return 0;
}