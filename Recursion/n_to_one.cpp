#include<iostream>
using namespace std;

int NtoOne(int n){
    if(n==0){
        return 0;
    }
    else{
        cout<<n<<endl;
        NtoOne(n-1);
    }
}

int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    NtoOne(n);
    

    return 0;
}