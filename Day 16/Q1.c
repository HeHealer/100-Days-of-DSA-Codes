/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/

#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    int a[n];
    int arr[n];
    for(i=0;i<n;i++)
    {
        arr[i]=0;
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            continue;
        }
        int count=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                count++;
                arr[j]=1;
            }
        }
        printf("%d:%d ",a[i],count);
    }
}