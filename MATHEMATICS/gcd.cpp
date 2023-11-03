#include<iostream>
using namespace std;

int GCD(int a, int b){
    int res = min(a,b);

    while (res>0)
    {
        if(a%res == 0 && b&res == 0){
        return res;
    }
    else{
        res--;
    }
    }
    
}

int main(){
    int a = 10;
    int b = 20;

    cout<< GCD(a,b);

    return 0;
}