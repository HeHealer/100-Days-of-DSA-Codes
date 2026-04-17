/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2*/

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
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* build(int *a,int n)
{
    struct node* nodes[n];
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

struct node* lca(struct node *root,int n1,int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==n1 || root->data==n2)
    {
        return root;
    }
    struct node *l=lca(root->left,n1,n2);
    struct node *r=lca(root->right,n1,n2);
    if(l!=NULL && r!=NULL)
    {
        return root;
    }
    if(l!=NULL)
    {
        return l;
    }
    return r;
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
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    struct node *ans=lca(root,n1,n2);
    printf("%d",ans->data);
    return 0;
}