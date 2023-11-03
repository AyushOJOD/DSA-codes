#include<bits/stdc++.h>
using namespace std;

int main(){

    pair<int, int> p = {1,2};

    // can be accessed through p.first and p.second

    cout<<p.first<<" "<<p.second<<endl;

    // Nested pair 

    pair<int, pair<int, int>> nested = {1, {2,3}};

    //can be accessed through nested object model;

    cout<<nested.first<<" "<<nested.second.first<<" "<<nested.second.second<<endl; 

    // A large number of pairs can be stored using array

    pair<int, int> arr[] = {{1,2},{3,4},{5,6}};

    // Can be accessed in similar mannner

    cout<<arr[1].first<<" "<<arr[0].second;

    return 0;
}