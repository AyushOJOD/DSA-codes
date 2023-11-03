#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }


    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i] == i+1){
            count++;
        }
    }

    if(count%2 == 0){
        cout<<(count/2);
    }
    else{
        cout<<((count/2)+1);
    }


    return 0;
}