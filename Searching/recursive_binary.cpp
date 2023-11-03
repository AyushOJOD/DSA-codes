#include<bits/stdc++.h>
using namespace std;

int recursiveBinary(int arr[], int k, int low, int high){

    if(low>high){
        return -1;
    }

    int mid = (low+high)/2;

    if(arr[mid] == k){
        return mid;
    }
    else if(arr[mid]>k){
        return recursiveBinary(arr,k,low,mid-1);
    }
    else{
        return recursiveBinary(arr,k,mid+1,high);
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

    cout<<recursiveBinary(a,6,0,n-1);

    return 0;
}