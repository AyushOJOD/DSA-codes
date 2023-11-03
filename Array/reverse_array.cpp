#include<bits/stdc++.h>
using namespace std;

int revArray(int arr[], int n){
    int first = 0;
    int last = n-1;

    for(int i=0;i<n;i++){
        while(first<last){
            int temp;
        temp = arr[first];
        arr[first]=arr[last];
        arr[last]=temp;
        first++;
        last--;
        }
    }

    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
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

    cout<<revArray(a,n);

    return 0;
}