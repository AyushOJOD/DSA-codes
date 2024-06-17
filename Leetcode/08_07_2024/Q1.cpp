#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (isdigit(ch))
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }

    string res = "";
    while (!st.empty())
    {
        char ch = st.top();
        res.push_back(ch);
        st.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{

    return 0;
}