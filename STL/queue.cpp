#include<bits/stdc++.h>
using namespace std;

int main(){

    // FIRST IN FIRST OUT

    queue<int> q;
    q.push(1); //{1}
    q.push(2); //{1,2}
    q.emplace(3); //{1,2,3}

    cout<<q.back();  // Gives the last element

    q.pop(); //{2,3}

    return 0;
}