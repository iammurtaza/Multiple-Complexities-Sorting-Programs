#include <iostream>

using namespace std;

void insertsort(int a[],int n){
    int i,hole,val;
    for(i=1;i<n;i++){
        val=a[i];
        hole=i;
        while(hole>0 && a[hole-1]>val) {
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=val;
    }
}


int main()
{   int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    insertsort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
