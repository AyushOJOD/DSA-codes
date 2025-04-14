#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodedString(string &s)
    {
        // code here
        stack<string> st;

        for (char ch : s)
        {
            if (ch == ']')
            {
                string repeating = "";
                while (!st.empty() && !isdigit(st.top()[0]))
                {
                    string top = st.top();
                    repeating += (top == '[') ? "" : top;
                    st.pop();
                }

                string numericTimes = "";
                while (!st.empty() && isdigit(st.top()[0]))
                {
                    numericTimes += st.top();
                    st.pop();
                }

                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);

                string currDecode = "";

                while (n--)
                {
                    currDecode += repeating;
                }

                st.push(currDecode);
            }
            else
            {
                string temp(1, ch);
                st.push(temp);
            }
        }

        string res = "";
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return ans
    }
};

int main()
{

    return 0;
}