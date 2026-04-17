/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int data)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node* build(int *a,int n)
{
    struct node **nodes=(struct node**)malloc(n*sizeof(struct node*));
    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        {
            nodes[i]=NULL;
        }
        else
        {
            nodes[i]=createNode(a[i]);
        }
    }
    int j=1;
    for(int i=0;i<n && j<n;i++)
    {
        if(nodes[i]!=NULL)
        {
            if(j<n)
            {
                nodes[i]->left=nodes[j++];
            }
            if(j<n)
            {
                nodes[i]->right=nodes[j++];
            }
        }
    }
    return nodes[0];
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    struct node *root=build(a,n);
    if(root==NULL)
    {
        return 0;
    }
    struct node *q[1000];
    int f=0,r=0;
    q[r++]=root;
    while(f<r)
    {
        int size=r-f;
        int val=0;
        for(int i=0;i<size;i++)
        {
            struct node *cur=q[f++];
            val=cur->data;
            if(cur->left!=NULL)
            {
                q[r++]=cur->left;
            }
            if(cur->right!=NULL)
            {
                q[r++]=cur->right;
            }
        }
        printf("%d ",val);
    }
    return 0;
}