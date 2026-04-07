//Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include<stdio.h>
void heapify(int a[], int n, int i){
    int largest=i,l=2*i+1,r=2*i+2,t;
    if(l<n&&a[l]>a[largest]){
        largest=l;
    }
    if(r<n&&a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify(a,i,0);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i;i<n;i++){
        scanf("%d",&a[i]);
    }
    heapSort(a,n);
    for(int i;i<n;i++){
        scanf("%d",&a[i]);
    }
}