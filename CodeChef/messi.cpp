#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
    int x,y,z;
    cin>>x>>y>>z;

    int xy=x*y;
    int yz=y*z;
    int xz=x*z;

    if(xy%z == 0 && xy>z){
        cout<<xy<<" "<<z;
        return 0;
    }
    else if(yz%x == 0 && yz>x){
        cout<<yz<<" "<<x;
        return 0;
    }
    else if(xz%y == 0 && xz>y){
        cout<<xz<<" "<<y;
        return 0;
    }
    else{
        cout<<"-1";
    }
    }

    return 0;
}