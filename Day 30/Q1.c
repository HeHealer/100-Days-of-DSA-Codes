/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int c,e;
    struct node* next;
};
int main(){
    int n,c,e;
    struct node* head=NULL,*temp,**curr=&head;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&c,&e);
        temp=(struct node*)malloc(sizeof(struct node));
        temp->c=c;
        temp->e=e;
        temp->next=NULL;
        *curr=temp;
        curr=&temp->next;
    }
    for(temp=head;temp;temp=temp->next){
        if(temp!=head){
            printf(" + ");
        }
        if(temp->e==0){
            printf("%d",temp->c);
        }
        else if (temp->e == 1){
            printf("%dx", temp->c);
        }
        else{
            printf("%dx^%d", temp->c, temp->e);
        }
    }
}