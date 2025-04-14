#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && s[i] == '*')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        s = "";

        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }

        return s;
    }
};

int main()
{

    return 0;
}