/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, m, x;
    if (scanf("%d", &n) != 1) return 0;
    int *q = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    if (scanf("%d", &m) != 1) return 0;
    int front = m % n;
    for (int i = 0; i < n; i++) {
        printf("%d%c", q[(front + i) % n], i == n - 1 ? '\n' : ' ');
    }
    free(q);
    return 0;
}