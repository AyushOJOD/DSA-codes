#include<bits/stdc++.h>
using namespace std;

void selectionSrt(int arr[], int n){
    int temp[n];
    for(int i=0;i<n;i++){
        int min_ind = 0;
        for(int j=1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind = j;
            }
            temp[i]=arr[min_ind];
            arr[min_ind]=INT_MAX;
        }
    }

    for(int k=0;k<n;k++){
        arr[k]=temp[k];
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

    selectionSrt(a,n);

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    

    return 0;
}