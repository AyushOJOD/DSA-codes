#include<iostream>
using namespace std;

bool isPrime(int n){
        if(n==1){
        return false;
    }
    for (int i = 2 ; i < n; i++)
    {
        if(n%i == 0){
            return false;
        }
        else{
            return true;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    
    cout<<isPrime(n);
    
    

    return 0;
}