#include <bits/stdc++.h>
using namespace std;
#define int long long int


void solve() {
int a,b,c;
cin>>a>>b>>c;
if(b>a){
    swap(a,b);
}
int res=0;
while(a>b){
    a-=c;b+=c;
res++;
}
cout<<res<<"\n";
}


signed main(){
    int tes;
    cin>>tes;
    while(tes--){
        solve();
    }
}