#include <bits/stdc++.h>
using namespace std;

// pbbcggttcppooaais

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.length();

        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++)
        {
            if (!st.empty())
            {
                if (s[i] == st.top().first)
                {
                    if (st.top().second == k - 1)
                    {
                        for (int i = 0; i < k - 1; i++)
                        {
                            st.pop();
                        }
                    }
                    else
                    {
                        st.push({s[i], st.top().second + 1});
                    }
                }
                else
                {
                    st.push({s[i], 1});
                }
            }
            else
            {
                st.push({s[i], 1});
            }
        }

        string res = "";

        while (!st.empty())
        {
            res += st.top().first;
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main()
{

    return 0;
}