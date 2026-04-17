/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

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
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int height(struct node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh > rh)
    {
        return lh + 1;
    }
    else
    {
        return rh + 1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    struct node *nodes[n];
    for(int i = 0; i < n; i++)
    {
        if(a[i] == -1)
        {
            nodes[i] = NULL;
        }
        else
        {
            nodes[i] = createNode(a[i]);
        }
    }
    int j = 1;
    for(int i = 0; i < n && j < n; i++)
    {
        if(nodes[i] != NULL)
        {
            if(j < n)
            {
                nodes[i]->left = nodes[j++];
            }
            if(j < n)
            {
                nodes[i]->right = nodes[j++];
            }
        }
    }
    printf("%d", height(nodes[0]));
    return 0;
}