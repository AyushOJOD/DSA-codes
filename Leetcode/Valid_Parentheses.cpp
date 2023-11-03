#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if ((s[i] == ')' && st.top() == '(') || ((s[i] == '}' && st.top() == '{')) || ((s[i] == ']' && st.top() == '[')))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main()
{

    return 0;
}