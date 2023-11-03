#include<bits/stdc++.h>
using namespace std;

int rob(vector<int> num){
    int even = 0;
    int odd = 0;
    int n = num.size();

    for(int i=0;i<n;i=i+2){
        even = even+num[i];
    }
    for(int i=1;i<n;i=i+2){
        odd=odd+num[i];
    }

    return std::max(odd,even);
}

int main(){
    vector<int> num = {1,2,3,1};

    cout<<rob(num);

    return 0;
}