#include <bits/stdc++.h>
using namespace std;

class MinStack
{

    vector<vector<int>> st; //{val, minVal}

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int minVal = getMin();

        if (st.empty() || minVal > val)
        {
            minVal = val;
        }

        st.push_back({val, minVal});
    }

    void pop()
    {
        int minVal;
        if (!st.empty())
        {
            minVal = st[st.size() - 1][1];
            st.pop_back();
        }

        if (!st.empty())
        {
            st[st.size() - 1][1] = minVal;
        }
    }

    int top()
    {
        return st[st.size() - 1][0];
    }

    int getMin()
    {
        return st[st.size() - 1][1];
    }
};

int main()
{

    return 0;
}