#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(string &s, string req, int value)
    {
        stack<char> st;
        int gain = 0;

        for (char &it : s)
        {
            if (st.empty())
            {
                st.push(it);
            }
            else
            {
                if (st.top() == req[0] && it == req[1])
                {
                    st.pop();
                    gain += value;
                }
                else
                {
                    st.push(it);
                }
            }
        }

        s = "";

        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(), s.end());

        return gain;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        string req1 = "ab", req2 = "ba";

        if (x < y)
        {
            swap(req1, req2);
            swap(x, y);
        }

        return helper(s, req1, x) + helper(s, req2, y);
    }
};

int main()
{

    return 0;
}