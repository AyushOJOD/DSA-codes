#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> helper(string s)
    {
        vector<int> res;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                vector<int> prefixVal = helper(s.substr(0, i));
                vector<int> suffixVal = helper(s.substr(i + 1));

                for (int x : prefixVal)
                {
                    for (int y : suffixVal)
                    {
                        if (s[i] == '+')
                        {
                            res.push_back(x + y);
                        }
                        else if (s[i] == '-')
                        {
                            res.push_back(x - y);
                        }
                        else
                        {
                            res.push_back(x * y);
                        }
                    }
                }
            }
        }

        if (res.empty())
        {
            res.push_back(stoi(s));
        }

        return res;
    }

public:
    vector<int> diffWaysToCompute(string expression)
    {
        return helper(expression);
    }
};

int main()
{

    return 0;
}