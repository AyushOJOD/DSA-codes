#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n==1){
        return false;
    }

    for(int i=2; i*i<n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


int primeFactors(int n){
    for(int i=2; i<n; i++){
        int x=i;
        if(isPrime(i)){
            while(n%x == 0){
                cout<<i<<endl;
                x=x*i;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<primeFactors(n);
    

    return 0;
}