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

int searchInfinite(int arr[], int k){

    if(arr[0] == k){
        cout<<"0";
        }
    while(true){
        int i=1;
    
        if(arr[i] == k){
            return i;
        }
        else if(arr[i]>k){
            recursiveBinary(arr,k,0,i);
        }
        else{
            i=i*2;
        }
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

    int k;
    cout<<"\nEnter element to be searched in infinite array:";
    cin>>k;

    searchInfinite(a, k);

    return 0;
}