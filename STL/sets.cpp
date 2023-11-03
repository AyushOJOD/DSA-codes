#include<bits/stdc++.h>
using namespace std;

int main(){

    // Stores unique and sorted data
    set<int> st;

    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(5);
    st.insert(4);

    auto it = st.find(4);

    int cnt = st.count(2);  // It is a boolean returning 0 and 1


    return 0;
}