#include<iostream>
using namespace std;

int conscutiveOnes(int n){
    int count=0;
    while(n>0){
        if((n&1)==1){
            count++;
            n=n>>1;
        }
        else if((n&1)==0){
            count=0;
            n=n>>1;
        }
    }
    return count;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<conscutiveOnes(n);

    return 0;
}