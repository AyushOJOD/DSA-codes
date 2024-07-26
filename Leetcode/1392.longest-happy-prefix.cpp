#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.length();

        if (n == 0)
        {
            return "";
        }

        long long prefix_hash = 0, suffix_hash = 0;
        long long base = 31;
        long long mod = 1e9 + 7;
        long long curr_max = 0;
        long long power = 1;

        for (int i = 0; i < n - 1; i++)
        {
            prefix_hash = (prefix_hash * base + (s[i] - 'a' + 1)) % mod;
            suffix_hash = (suffix_hash + (s[n - i - 1] - 'a' + 1) * power) % mod;
            power = (power * base) % mod;

            if (prefix_hash == suffix_hash)
            {
                curr_max = i + 1;
            }
        }

        return s.substr(0, curr_max);
    }
};

int main()
{
    Solution obj;
    string s = "ababab";
    cout << obj.longestPrefix(s) << endl;
    return 0;
}
