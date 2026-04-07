/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{ 
    int val; 
    struct Node *next;
} Node;
Node *front=NULL, *rear=NULL;
void enqueue(int x){
    Node *n=malloc(sizeof(Node));
    n->val=x; 
    n->next=NULL;
    if(!rear){
        front=rear=n;
    }
    else {
        rear->next=n;
        rear=n;
    }
}
int dequeue(){
    if(!front){
        return -1;
    }
    int v=front->val;
    Node *t=front;
    front=front->next;
    if(!front){
        rear=NULL;
    }
    free(t);
    return v;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char op[20];
        scanf("%s",op);
        if(op[0]=='e' && op[1]=='n'){
            int x;
            scanf("%d",&x);
            enqueue(x);
        }
        else if(op[0]=='d'){
            printf("%d\n",dequeue());
        }
    }
}