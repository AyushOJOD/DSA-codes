#include <bits/stdc++.h>
using namespace std;

int evaluate_prefix(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
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
                int res = st.top() + temp;
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
        }

        st.pop();
        st.push(res);
    }

    return st.top();
}

int main()
{

    return 0;
}