/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next,*prev;
};
int main(){
    int n,val;
    struct node* head=NULL,*tail=NULL;
    scanf("%d",&n);
    if(n<=0)return 0;
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=val;
        temp->next=NULL;
        temp->prev=tail;
        if(!head){
            head=temp;
        }
        else{
            tail->next=temp;
        }
        tail=temp;
    }
    for(struct node* curr=head;curr;curr=curr->next){
        printf("%d%s",curr->data,curr->next?" ":"");
    }
}