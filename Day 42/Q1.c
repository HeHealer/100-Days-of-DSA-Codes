/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int q[n],s[n],top=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
        s[++top]=q[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d", s[top--]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
}