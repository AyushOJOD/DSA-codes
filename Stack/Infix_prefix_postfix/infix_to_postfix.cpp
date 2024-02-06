#include <bits/stdc++.h>
using namespace std;

string infix_to_postfix(string s)
{
    stack<char> st;

    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - 'a' > 0 && s[i] - 'a' < 26)
        {
            res += s[i];
        }
        else
        {
            if (s[i] == "(")
            {
                st.push(s[i]);
            }
            else if (s[i] == ")")
            {
                while (!st.empty() && st.top() != "(")
                {
                    res += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && st.top() != "(" && precedence(st.top()) > precedence(s[i]))
                {
                    res += st.top();
                    st.pop();
                }
            }
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{

    return 0;
}