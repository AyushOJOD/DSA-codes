#include<iostream>
using namespace std;

int setBits(int n){
    int res=0;
    while(n>0){
        if((n&1)!=0){
            res++;  
            n=n/2;
        }
        else{
            n=n/2;
        }
    }
    return res;
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<setBits(n);

    return 0;
}