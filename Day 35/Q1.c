/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void enqueue(struct Node** front, struct Node** rear, int val){
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (*rear == NULL){
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}
int main() {
    struct Node *front = NULL, *rear = NULL;
    int n, val;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++){
        scanf("%d", &val);
        enqueue(&front, &rear, val);
    }
    for (struct Node* t = front; t != NULL; t = t->next){
        printf("%d%s", t->data, t->next ? " " : "");
    }
}