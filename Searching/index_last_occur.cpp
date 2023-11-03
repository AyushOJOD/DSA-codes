#include<bits/stdc++.h>
using namespace std;

int lastOccur(int arr, int n, int k, int low, int high){
    int low=0;
    int high=n-1;

    if (high < low) {
        return -1;
    }

    int mid = (low+high)/2;

    if(arr[mid] > k){
        //search in left half only.
        return lastOccur(arr, n,k, low, mid-1);
    }
    else if(arr[mid]<k){
        // search in right half only.
        return lastOccur(arr,n,k,mid+1,high);
    }
    else{
        cout<<mid<<endl;
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

    cout<<lastOccur()

    return 0;
}