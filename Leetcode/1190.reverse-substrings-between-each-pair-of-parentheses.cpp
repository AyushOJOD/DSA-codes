#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        int n = s.length();
        vector<int> bracket(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                int idx = i;
                st.pop();
                bracket[i] = idx;
                bracket[idx] = i;
            }
        }

        string ans = "";
        int direction = 1;

        for (int i = 0; i < n; i = i + direction)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                i = bracket[i];
                direction = direction * -1;
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}