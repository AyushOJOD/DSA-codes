#include<iostream>
using namespace std;

int sumUptoN(int n){
    if(n==0){
        return 0;
    }
    return n+sumUptoN(n-1);
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    
    cout<<sumUptoN(n);

    return 0;
}