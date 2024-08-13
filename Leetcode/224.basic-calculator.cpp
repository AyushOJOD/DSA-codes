#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();
        int result = 0, number = 0, sign = 1;
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                number = (10 * number) + stoi(s[i]);
            }
            else if (s[i] == '+')
            {
                result += number * sign;
                sign = 1;
                number = 0;
            }
            else if (s[i] == '-')
            {
                result += number * sign;
                sign = -1;
                number = 0;
            }
            else if (s[i] == '(')
            {
                st.push(result);
                st.push(sign);

                result = 0, number = 0, sign = 1;
            }
            else if (s[i] == ')')
            {
                result += (number * sign);
                number = 0;

                int op = st.top();
                st.pop();

                int last_res = st.top();
                st.pop();

                result *= op;
                result += last_res;
            }
        }

        result += (number * sign);
        return result;
    }
};

int main()
{

    return 0;
}