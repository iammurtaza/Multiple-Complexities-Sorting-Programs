#include <iostream>
// Divide and Conquer Problem
// Recursive Algorithm
// Stable sort - Retains the relative order of records with same key
// Not an In place sort - Extra memory needed - Space complexity - O(n)
// Time complexity - O(n.log n)
using namespace std;

void merg(int a[],int left[],int l, int right[], int r){
    int i=0,j=0,k=0;
    while(i<l || j<r)
        if( (left[i]<right[j] || j==r) && i!=l )
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
}

// Simpler way to write the merg function will be
void merg2(int a[],int left[],int l, int right[], int r){
    int i=0,j=0,k=0;
    while(i<l && j<r){
        if(left[i] < right[j])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }
    while(i<l)
        a[k++]=left[i++];

    while(j<r)
        a[k++]=right[j++];
}

void mergesort(int a[],int n){
    if(n<2)
        return;
    int mid=n/2,i, left[mid], right[n-mid];
    for(i=0;i<mid;i++)
        left[i]=a[i];
    for(i=mid;i<n;i++)
        right[i-mid]=a[i];
    mergesort(left,mid);
    mergesort(right,n-mid);
    merg2(a, left, mid, right, n-mid);
}

int main(){
    int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
