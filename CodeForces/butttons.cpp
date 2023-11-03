#include<bits/stdc++.h>
using namespace std;

void buttonGame(int a, int b, int c){
    
    if(a>b){
        cout<<"First";
    }
    else if(b>a){
        int diff = b-a;
        if(c%2 != 0){  // c is odd
            if(diff>=1){
                cout<<"Second";
            }
            else{
                cout<<"First";
            }
        }
        else{
            // c is even
            cout<<"Second";
        }
    }
}

int main(){
    int a,b,c;

    
    cin>>a>>b>>c;

    buttonGame(a,b,c);

    return 0;
}