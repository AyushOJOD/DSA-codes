#include<bits/stdc++.h>
using namespace std;


int num(vector<vector<int>>& nums){
    set <int> s;
    for(int i=0;i<nums.size();i++){
        for(int j=nums[i][0]; j<nums[i][1]; j++){
            s.insert(j);
        }
    }

    cout<<s.size();
}

int main(){
    

    return 0;
}