#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();

    stack<int> st;
    vector<int> res(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= A[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            res[i] = st.top();
        }

        st.push(A[i]);
    }
    return res;
}

int main()
{

    return 0;
}