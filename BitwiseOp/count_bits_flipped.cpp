#include<iostream>
using namespace std;

int countFlipped(int a, int b){
    int res=(a^b);
    int count=0;
    while(res){
        count = count+(res&1);
        res=res>>1;
    }
    return count;
}

int main(){
    int a,b;
    cout<<"Enter the value of a: ";
    cin>>a;
    cout<<"Enter the value of b: ";
    cin>>b;

    cout<<countFlipped(a,b);

    return 0;
}