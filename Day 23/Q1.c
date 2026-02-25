/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* create(int value){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    return new;
}
struct node* build(int count){
    if(count<=0)
    {
        return NULL;
    }
    int val;
    scanf("%d",&val);
    struct node* head=create(val);
    struct node* current=head;
    for(int i=1;i<count;i++)
    {
        scanf("%d",&val);
        current->next=create(val);
        current=current->next;
    }
    return head;
}
struct node* merge(struct node* t1,struct node* t2){
    if(!t1) return t2;
    if(!t2) return t1;
    struct node* head=NULL;
    if(t1->data<=t2->data)
    {
        head=t1;
        t1=t1->next;
    }
    else
    {
        head=t2;
        t2=t2->next;
    }
    struct node* curr=head;
    while(t1 && t2){
        if(t1->data<=t2->data)
        {
            curr->next=t1;
            t1=t1->next;
        }
        else
        { 
            curr->next=t2;
            t2=t2->next;
        }
        curr=curr->next;
    }
    if(t1) curr->next=t1;
    else curr->next=t2;
    return head;
}
void print(struct node *head){
    while(head)
    {
        printf("%d%s",head->data,head->next?" ":"");
        head=head->next;
    }
    printf("\n");
}
int main(){
    int n,m;
    if(scanf("%d",&n)!=1) return 0;
    struct node* t1=build(n);
    if(scanf("%d",&m)!=1) return 0;
    struct node* t2=build(m);
    struct node* result=merge(t1,t2);
    print(result);
}