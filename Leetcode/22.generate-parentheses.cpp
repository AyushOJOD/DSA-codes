#include <bits/stdc++.h>
using namespace std;

bool isValid(string &curr)
{
    stack<char> st;

    for (int i = 0; i < curr.length(); i++)
    {
        if (curr[i] == '(')
        {
            st.push(curr[i]);
        }
        else
        {
            if (st.size())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

void func(string &curr, int n, vector<string> &res, int open, int close)
{
    if (curr.size() == 2 * n)
    {
        if (isValid(curr))
        {
            res.push_back(curr);
            return;
        }
    }

    if (open < n)
    {
        curr.append("(");
        func(curr, n, res, open + 1, close);
        curr.pop_back();
    }

    if (close < open)
    {
        curr.append(")");
        func(curr, n, res, open, close + 1);
        curr.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string curr = "";
    func(curr, n, res, 0, 0);

    return res;
}

int main()
{

    return 0;
}