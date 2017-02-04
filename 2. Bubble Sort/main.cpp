#include <iostream>

using namespace std;

void bubblesort(int *a,int n){
    int i,j,small,temp,pos,flag;
    for(j=0;j<n-1;j++){
        flag=0;
        for(i=0;i<n-j;i++){
            if(a[i]>a[i+1]){
                swap(a[i+1],a[i]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}


int main()
{   int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    bubblesort(a,n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
