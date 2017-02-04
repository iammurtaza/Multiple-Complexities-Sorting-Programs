#include <iostream>
#include <random>

#include <time.h> // For method 2
#include <stdlib.h> // For method 2

using namespace std;
// Divide and conquer Algorithm
// Recursive Algorithm
// Not stable
// Best and average case running time - O(n.log n)
// Worst case - O(n^2) - Only when list is already sorted - Can be avoided if we use randomized version of quick sort
// In place sorting algorithm
// Default libraries generally sort using quick sort

int partition(int a[],int start,int end){
    int partIndex=start;
    int pivot=a[end];
    for(int i=start;i<end;i++){
        if(a[i]<=pivot){
            swap(a[i],a[partIndex]);
            partIndex++;
        }
    }
    swap(a[partIndex],a[end]);
    return partIndex;
}

int randomizedpartition(int a[],int start, int end){
    /* Method 1
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(start, end); // define the range
    int randomindex = distr(eng);*/

    // Method 2 for random number
    srand(time(nullptr));
    int randomindex = (rand() % (end-start+1)) + start;

    swap(a[randomindex], a[end]);
    return partition(a,start,end);
}

void quicksort(int a[],int start,int end){
    if(start<end){
        int partIndex = randomizedpartition(a,start,end);
        // int partIndex = partition(a,start,end); Can be done using this too
        quicksort(a,start,partIndex-1);
        quicksort(a,partIndex+1,end);
    }
}

int main(){
    int i,n,a[100];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
