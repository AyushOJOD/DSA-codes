#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    char evaluate(string expr, char oper)
    {
        int res = (oper == '&') ? 1 : 0;

        if (oper == '|')
        {
            for (char ch : expr)
            {
                if (ch == 't')
                {
                    res |= 1;
                }
            }
        }
        else if (oper == '!')
        {
            res = (expr[0] == 't') ? 0 : 1;
        }
        else
        {
            for (char ch : expr)
            {
                if (ch == 'f')
                {
                    res &= 0;
                }
            }
        }

        return (res == 1) ? 't' : 'f';
    }

public:
    bool parseBoolExpr(string expression)
    {
        stack<char> st;
        int n = expression.length();

        for (char ch : expression)
        {
            if (ch == ')')
            {
                string tf = "";
                while (!st.empty() && st.top() != '(')
                {
                    if (st.top() != ',')
                    {
                        tf += st.top();
                    }
                    st.pop();
                }
                st.pop(); // To remove the '('

                char oper = st.top();
                st.pop();

                char value = evaluate(tf, oper);

                st.push(value);
            }
            else
            {
                st.push(ch);
            }
        }

        return st.top() == 't';
    }
};

int main()
{

    return 0;
}