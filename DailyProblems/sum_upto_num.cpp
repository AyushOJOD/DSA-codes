#include<iostream>
using namespace std;

long long sumUptoNum(int n){
    cout<<(n)*(n-1)/2;
}

int main(){
    int n;
    cin>>n;
    sumUptoNum(n);

    return 0;
}