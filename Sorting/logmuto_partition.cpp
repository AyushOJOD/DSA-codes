#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h){
    int pivot = arr[h];  // Always last
    int i = l-1;

    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }

    swap(arr[i+1], arr[h]);  // Bring the pivot to its position!

    return (i+1);

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