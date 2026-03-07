/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void push(struct Node** top, int val) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}
int pop(struct Node** top)
{
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}
int a(char* s)
{
    int res = 0, sign = 1;
    if (s[0] == '-'){
         sign = -1; int i = 1; 
        }
    for (int i=0; s[i] != '\0'; i++){
        res = res * 10 + (s[i] - '0');
    }
    return res * sign;
}
int main() {
    struct Node* stack = NULL;
    char s[20];
    while (scanf("%s", s) != EOF)
    {
        if (s[1] == '\0' && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
        {
            int b = pop(&stack);
            int a = pop(&stack);
            if (s[0] == '+') push(&stack, a + b);
            else if (s[0] == '-') push(&stack, a - b);
            else if (s[0] == '*') push(&stack, a * b);
            else if (s[0] == '/') push(&stack, a / b);
        }
        else
        {
            push(&stack, a(s));
        }
        if (getchar() == '\n') break;
    }
    printf("%d\n", pop(&stack));
}