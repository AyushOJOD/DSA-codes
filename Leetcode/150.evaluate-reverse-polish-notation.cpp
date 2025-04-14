#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;

        for (string &token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();

                if (token == "+")
                    stk.push(a + b);
                else if (token == "-")
                    stk.push(a - b);
                else if (token == "*")
                    stk.push(a * b);
                else if (token == "/")
                    stk.push(a / b);
            }
            else
            {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};

int main()
{
    Solution sol;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(tokens) << endl; // Output: 6
    return 0;
}
