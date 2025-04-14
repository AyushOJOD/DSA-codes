#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;

        string curr = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (curr != "")
                {
                    st.push(curr);
                    curr = "";
                }
            }
            else
            {
                curr += s[i];
            }
        }

        if (curr != "")
        {
            st.push(curr);
        }

        string res = "";

        while (!st.empty())
        {
            res += st.top();
            st.pop();
            if (!st.empty())
            {
                res += " ";
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}