#include<bits/stdc++.h>
using namespace std;

// int firstOccur(int arr[], int n, int k){
//     for(int i=0;i<n;i++){
//         if(arr[i] == k){
//             cout<<i<<endl;
//             break;
//         }
//     }
//     return -1;
// }

// better Approach by recursion

int firstOccur(int arr[], int k, int low, int high){
    low = 0;
    high = n-1;

    if(low>high){
        return -1;
    }
    
    int mid=(low+high)/2;

    if(arr[mid] == k){
        if(arr[mid] != arr[mid-1] || mid==0){
            cout<<mid;
        }
        else{
            firstOccur(arr,k,low,mid-1);
        }
    }
    else if(arr[mid]>k){
        firstOccur(arr,k,low,mid-1);
    }
    else{
        firstOccur(arr,k,mid+1,high);
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

    int k=5;

    cout<<firstOccur(a,k,0,6);    

    return 0;
}