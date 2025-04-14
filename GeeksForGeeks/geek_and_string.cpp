#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removePair(string s)
    {
        stack<char> st;

        for (char ch : s)
        {
            if (!st.empty())
            {
                char top = st.top();
                if (top == ch)
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ch);
            }
        }

        string ans;

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    return 0;
}