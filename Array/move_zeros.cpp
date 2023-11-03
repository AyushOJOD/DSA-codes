#include<bits/stdc++.h>
using namespace std;

int ZeroToEnd(int arr[], int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[count]);
            count++;
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

    return 0;
}