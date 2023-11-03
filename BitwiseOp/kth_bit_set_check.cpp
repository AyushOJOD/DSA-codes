#include<iostream>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the bit: ";
    cin>>k;

    int m=(1<<(k-1));

    if((n&k) != 0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}