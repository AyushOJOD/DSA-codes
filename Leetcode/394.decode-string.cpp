#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == ']')
            {
                string temp = "";

                while (st.top() != "[")
                {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();

                int value = stoi(st.top());
                st.pop();

                string repeat = "";

                for (int i = 0; i < value; i++)
                {
                    repeat += temp;
                }

                st.push(repeat);
            }
            else if (isdigit[s[i]])
            {
                string num = "";
                while (i < n && isdigit[s[i]])
                {
                    num += s[i];
                    i++;
                }
                i--;
                st.push(num);
            }
            else
            {
                st.push(string(1, s[i]));
            }
        }

        return st.top();
    }
};

int main()
{

    return 0;
}