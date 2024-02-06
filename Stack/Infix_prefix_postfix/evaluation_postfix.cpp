#include <bits/stdc++.h>
using namespace std;

int evaluation(string s)
{

    stack<char> st;

    st.push(s[0]);
    st.push(s[1]);

    for (int i = 2; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            int temp = st.top();
            st.pop();
            switch (operator)
            {
            case '+':
                int res = temp + st.top();
                break;
            case '-':
                int res = st.top() - temp;
                break;
            case '*':
                int res = st.top() * temp;
                break;
            case '/':
                int res = st.top() / temp;
            default:
                break;
            }
            st.pop();
            st.push(res);
        }
    }

    return st.top();
}

int main()
{

    return 0;
}