/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* build(int count){
    struct node* head=NULL,*t=NULL;
    int v;
    for(int i=0;i<count;i++){
        scanf("%d",&v);
        struct node* n=(struct node*)malloc(sizeof(struct node));
        n->data=v;
        n->next=NULL;
        if(head==NULL){
            head=t=n;
        }
        else{
            t->next=n;
            t=n;
        }
    }
    return head; 
}
int main(){
    int n,m;
    scanf("%d",&n);
    struct node* h1=build(n);
    scanf("%d",&m);
    struct node* h2=build(m);
    struct node* p1=h1,*p2=h2;
    while(p1&&p2&&p1->data!=p2->data){
        p1=p1->next;
        p2=p2->next;
        if(p1==p2)break;
        if(!p1)p1=p2;
        if(!p2)p2=p1;
    }
    if(p1&&p2){
        printf("%d",p1->data);
    }
    else{
        printf("No Intersection");
    }
}