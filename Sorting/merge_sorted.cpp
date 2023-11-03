#include<bits/stdc++.h>
using namespace std;

int mergeSorted(int a[], int b[], int m, int n){
    int i = 0;
    int j=0;

    while(i<m && j<n){
        if(a[i]>=b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else{
            cout<<a[i]<<" ";
            i++;
        }
    }

    while(i<m){
        cout<<a[i]<<" ";
        i++;
    }
    while(j<n){
        cout<<b[j]<<" ";    
        j++;    
    }
    
}

int main(){
    int m;
    cout<<"Enter the number of elements: ";
    cin>>m;

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[m];
    for(int i=0;i<m;i++){
        cin>>a[i]<<;
    }

    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    cout<<mergeSorted(a,b,m,n);

    return 0;
}