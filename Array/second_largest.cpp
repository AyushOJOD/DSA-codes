#include<bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n){
    int largest = INT_MIN;
    int secondlar = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
            secondlar=largest;
        }
        else{
            if(arr[i]>secondlar && arr[i]<largest){
                secondlar=arr[i];
            }
        }
    }
}

int main(){

    return 0;
}