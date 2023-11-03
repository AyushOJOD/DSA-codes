#include<iostream>
using namespace std;

int oneToN(int n){

    if(n==0){
        return 0;
    }
    oneToN(n-1);
    cout<<n<<" ";,,,
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    oneToN(n);

    return 0;
},