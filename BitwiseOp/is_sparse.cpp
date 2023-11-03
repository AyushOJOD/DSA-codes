#include<iostream>
using namespace std;

bool isSparse(int n){ṇṇ
    if(n&(n>>1) != 0){
        return false;
    }
    return true;
}

int main(){
    int n;
    cout<<"Enter the value: ";
    cin>>n;

    cout<<isSparse(n);

    return 0;
}