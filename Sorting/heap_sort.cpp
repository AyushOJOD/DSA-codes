#include<bits/stdc++.h>
using namespace std;

int heapify(int arr[], int n, int i){
    // Find largest among root and children.
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]); // To get the new value of i;
        heapify(arr, n, largest);
    }
}

int heapSort(int arr[], int n){
    int size=n;

    while (size>1)
    {
        // Step 1 : Swap arr[n], arr[1];
        swap(arr[1], arr[size]);
        size--;

        // Step 2: heapify for rest of the array ;
        heapify(arr , size, 1);
    }
    
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    return 0;
}