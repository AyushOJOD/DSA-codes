#include<iostream>
using namespace std;

bool powerofTwo(int n){
    if(n==0){
        return false;
    }
    else{
        while(n != 1){
            if(n%2 != 0){
                return false;
            }
            n=n/2;
        }
        return true;
    }
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<powerofTwo(n);

    return 0;
}