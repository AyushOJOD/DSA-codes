#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),d(n);
        map<int,int> manage;
        for(auto &i:a){
            cin>>i;
        }
        for(auto &i:d){
            cin>>i;
            manage[i]++;
        }
        for(auto i:a){
            manage[i]++;
        }
        int mx=0;
        for(auto x:manage)mx = max(mx,x.second);
        cout<<mx<<endl;

    }

    return 0;
}