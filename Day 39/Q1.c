/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int h[10000],n=0;
void up(int i){
    while(i>0 && h[i]<h[(i-1)/2]){
        int t=h[i]; h[i]=h[(i-1)/2];
        h[(i-1)/2]=t; i=(i-1)/2;
    }
}
void down(int i){
    int c;
    while(2*i+1<n){
        c=2*i+1;
        if(c+1<n&&h[c+1]<h[c])c++;
        if(h[i]<=h[c]) break;
        int t=h[i];
        h[i]=h[c];
        h[c]=t;
        i=c;
    }
}
void insert(int x){
    h[n]=x;
    up(n);
    n++;
}
int extractMin(){
    if(n==0)return -1;
    int r=h[0];
    h[0]=h[--n];
    down(0);
    return r;
}
int peek(){
    return n? h[0]: -1;
}
int main() {
    int N; 
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        char line[50];
        if(!fgets(line, sizeof(line), stdin)) break;
        line[strcspn(line, "\n")] = 0;
        if(strncmp(line, "insert", 6) == 0){
            int x;
            sscanf(line + 7, "%d", &x);
            insert(x);
        }
        else if(strcmp(line, "extractMin") == 0){
            printf("%d\n",extractMin());
        }
        else if(strcmp(line, "peek") == 0){
            printf("%d\n",peek());
        }
    }
}