#include<bits/stdc++.h>
using namespace std;

int maxval(int arr[], int n){
    int a=0;
    int c=n;

    int l=0;
    int r=n;

    while(l<=r && l+1!=r-1){
        if(arr[l]<arr[l+1]){
            l++,a++;
        }
        else{
            l++;
        }

        if(arr[r]<arr[r-1]){
            r--;c--;
        }
        else{
            r--;
        }
    }

    int b=arr[a];
    for(int i=a;i<c;i++){
        if(arr[i]<b){
            b=arr[i];
        }
    }

    return a;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<maxval(a,n);

    return 0;
}