#include <iostream>

using namespace std;
int a[100],n;

void max_heapify(int i){
    int l=2*i+1;
    int r=2*i+2;
    int lrgst=i;
    if(l<n && a[l]>a[i])
        lrgst=l;
    if(r<n && a[r]>a[lrgst])
        lrgst=r;
    if(lrgst!=i){
        swap(a[i],a[lrgst]);
        max_heapify(lrgst);
    }
}

void build_max_heap(){
    for(int i=(n-1)/2;i>=0;i--)
        max_heapify(i);
}

int extract_max(){
    int max=a[0];
    a[0]=a[n-1];
    n--;
    max_heapify(0);
    return max;
}

void heap_sort(){
    build_max_heap();
    int temp=n;
    for(int i=n-1;i>=0;i--)
        a[i]=extract_max();
    n=temp;
}

/*void heap_sort(){
    build_max_heap();
    for(int i=n-1;i>=1;i--){
        swap(a[0],a[i]);
        n--;
        cout<<a[i]<<" ";
        max_heapify(0);
    }
    cout<<a[0];
}*/

void print(){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    heap_sort();
    print();
    return 0;
}
