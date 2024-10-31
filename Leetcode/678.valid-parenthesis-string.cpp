#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<char> st;
        stack<char> stClose;

        int star = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
            {
                star++;
            }
            else if (!st.empty() && s[i] == ')')
            {
                st.pop();
                stClose.push(s[i]);
            }
            else
            {
                st.push(s[i]);
            }
        }

        return st.size() <= star;
    }
};

int main()
{

    return 0;
}