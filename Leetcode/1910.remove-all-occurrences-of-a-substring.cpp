#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string result;
        int n = s.length(), m = part.length();
        char endChar = part.back();

        for (char ch : s)
        {
            result.push_back(ch);

            if (ch == endChar && result.size() >= m)
            {
                if (result.substr(result.size() - m) == part)
                {
                    result.erase(result.size() - m);
                }
            }
        }

        return result;
    }
};

int main()
{

    return 0;
}