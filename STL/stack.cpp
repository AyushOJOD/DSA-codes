#include<bits/stdc++.h>
using namespace std;

int main(){


    // LAST IN FIRST OUT
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3,2,1}

    cout<<st.top(); // gives the last inserted value 

    st.pop();

    return 0;
}