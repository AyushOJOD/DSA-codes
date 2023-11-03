#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int> pq; // It will place the elements according to the priority i.e, largest on TOP
    pq.push(3);
    pq.push(10);
    pq.push(-2);

    cout<<pq.top(); // Prints 10

    
    return 0;
}