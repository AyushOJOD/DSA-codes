#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;

    long long arr[n];

    for(long long j=0;j<n;j++){
        cin>>arr[j];
    }

    long long count = 0;

    for(long long i=0;i<n-1;i+=3){
        int sot = arr[i] + arr[i+1] + arr[i+2];
        int rem = sot%3;
        if(rem==0){
            count = count + 0;
        }
        else{
            count += 3-rem;
        }
    }

    cout<<count<<endl;

    return 0;
}