/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

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
    struct node **nodes=(struct node**)malloc(sizeof(struct node*)*n);
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
void reverse(int *arr,int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        int t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
        i++;
        j--;
    }
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
    int f=0;
    int r=0;
    q[r++]=root;
    int level=0;
    while(f<r)
    {
        int size=r-f;
        int temp[1000];
        for(int i=0;i<size;i++)
        {
            struct node *cur=q[f++];
            temp[i]=cur->data;
            if(cur->left)
            {
                q[r++]=cur->left;
            }
            if(cur->right)
            {
                q[r++]=cur->right;
            }
        }
        if(level%2==1)
        {
            reverse(temp,size);
        }
        for(int i=0;i<size;i++)
        {
            printf("%d ",temp[i]);
        }
        level++;
    }
    return 0;
}