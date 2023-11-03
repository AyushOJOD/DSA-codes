#include<iostream>
using namespace std;

int main(){
    int x=6;
    int y=3;

    cout<<(x&y)<<endl;  //& operator does AND the two numbers in their bit form

    cout<<(x|y)<<endl; //| operator does OR the two numbers in their bit form

    cout<<(x^y)<<endl; //^ operator does XOR the two numbers in their bit form

    cout<<(x<<1)<<endl; // << operator shifts the value of bit x in left by one bit

    cout<<(y>>2)<<endl; // >> shifts the value of bit y in right by two bits

    cout<<(~x)<<endl; // ~ gives the negation of every bit

    // all the negative numbers are stored in 2's complement form

    return 0;
}