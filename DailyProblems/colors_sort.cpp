#include<bits/stdc++.h>
using namespace std;

int colorSort(vector<int> nums){
    sort(nums);
    cout<<nums;
}

int main(){

    vector<int> v = {2,0,2,1,1,0};

    cout<<colorSort(v);

    return 0;
}