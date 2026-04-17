/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

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
struct Q
{
    struct node *t;
    int hd;
};
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
    struct Q q[1000];
    int f=0,r=0;
    int offset=1000;
    int hd_min=0,hd_max=0;
    int hd_list[2005][1000];
    int sz[2005]={0};
    q[r].t=root;
    q[r].hd=0;
    r++;
    while(f<r)
    {
        struct Q cur=q[f++];
        int idx=cur.hd+offset;
        hd_list[idx][sz[idx]++]=cur.t->data;
        if(cur.hd<hd_min)
        {
            hd_min=cur.hd;
        }
        if(cur.hd>hd_max)
        {
            hd_max=cur.hd;
        }
        if(cur.t->left!=NULL)
        {
            q[r].t=cur.t->left;
            q[r].hd=cur.hd-1;
            r++;
        }
        if(cur.t->right!=NULL)
        {
            q[r].t=cur.t->right;
            q[r].hd=cur.hd+1;
            r++;
        }
    }
    for(int i=hd_min+offset;i<=hd_max+offset;i++)
    {
        for(int j=0;j<sz[i];j++)
        {
            printf("%d ",hd_list[i][j]);
        }
        printf("\n");
    }
    return 0;
}