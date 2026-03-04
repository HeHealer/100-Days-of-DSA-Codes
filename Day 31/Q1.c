/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/

#include<stdio.h>
int main(){
    int n,a,val,s[100],t=-1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        if(a==1){
          scanf("%d",&val);
          s[++t]=val;
        }
        else if (a == 2) {
            if (t < 0) printf("Stack Underflow\n");
            else printf("%d\n", s[t--]);
        }
        else if (a == 3) {
            for (int i = t; i >= 0; i--) printf("%d ", s[i]);
            printf("\n");
        }
    }
}