#include<iostream>
using namespace std;

int sumDigits(int n){
    if(n==0){
        return 0;
    }
    

    return sumDigits(n/10) + n%10;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<sumDigits(n);

    return 0;
}