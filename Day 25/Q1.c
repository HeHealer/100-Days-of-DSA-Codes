/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int count(struct node* head,int key)
{
    int count=0;
    struct node* curr=head;
    while(curr!=NULL)
    {
        if(curr->data==key){
            count++;
        }
        curr=curr->next;
    }
    return count;
}
int main(){
    int n,key,value;
    struct node* head=NULL,*tail=NULL;
    if(scanf("%d",&n)!=1 || n<=0)
    {
        scanf("%d",&key);
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=value;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
            tail=new;
        }
    }
    scanf("%d",&key);
    printf("%d\n",count(head,key));
    struct node* temp;
    while(head!=temp)
    {
        temp=head;
        head=head->next;
        free(temp);\
    }
}