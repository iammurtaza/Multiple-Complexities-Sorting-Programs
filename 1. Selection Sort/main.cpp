#include <iostream>

using namespace std;

void selectsort(int *a,int n){
    int i,j,small,temp,pos;
    for(j=0;j<n-1;j++){
        small=a[j];
        for(i=j+1;i<n;i++)
            if(small>a[i]){
                small=a[i];
                pos=i;
            }
        swap(a[j],a[pos]);
    }
}


int main()
{   int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    selectsort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
