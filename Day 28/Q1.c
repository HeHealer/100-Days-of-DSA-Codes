/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    int n,val;
    scanf("%d",&n);
    struct node* head=NULL,*tail=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=val;
        temp->next=head;
        if(head==NULL)
        {
            head=temp;
            tail = temp;
            temp->next = head;
        }
        else
        {
            tail->next=temp;
            tail = temp;
            tail->next = head;
        }
    }
    struct node* curr=head;
    if (head != NULL) {
    do {
        printf("%d%s", curr->data, (curr->next != head) ? " " : "");
        curr = curr->next;
    } while (curr != head);
    printf("\n");
    }
    if(tail)tail->next=NULL;
    curr=head;
    while(curr){
        struct node* t=curr;
        curr=curr->next;
        free(t);
    }
}
