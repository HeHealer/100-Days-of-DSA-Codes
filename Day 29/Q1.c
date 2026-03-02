/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int main(){
    int n,k,val;
    scanf("%d",&n);
    if(n<=0) return 0;
    struct node* head=NULL,*tail=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val);
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=val;
        new->next=NULL;
        if(head==NULL){
            head=new;
        }
        else{
            tail->next=new;
        }
        tail=new;
    }
    scanf("%d",&k);
    if(n>0 && (k%=n)!=0){
        tail->next=head;
        for(int i=0;i<n-k;i++){
            tail=tail->next;
        }
        head=tail->next;
        tail->next=NULL;
        while(head){
            printf("%d%s",head->data,head->next?" ":"");
            struct node* temp=head;
            head=head->next;
            free(temp);
        }
    }
}