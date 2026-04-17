/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    int l=0;
    int r=n-1;
    int min_sum=1000000000;
    int x=0;
    int y=0;
    while(l<r)
    {
        int sum=a[l]+a[r];
        if(abs(sum)<abs(min_sum))
        {
            min_sum=sum;
            x=a[l];
            y=a[r];
        }
        if(sum<0)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    printf("%d %d",x,y);
    return 0;
}