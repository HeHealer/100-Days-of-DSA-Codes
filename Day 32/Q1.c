/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include<stdio.h>
int main(){
    int n,m,s[100],top=-1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&s[++top]);
    }
    scanf("%d",&m);
    top-=m;
    while(top>=0){
        printf("%d ",s[top--]);
    }
}