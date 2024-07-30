#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConvertString(string s, string t, int k)
    {
        int n = s.length();
        int m = t.length();

        if (n != m)
        {
            return false;
        }

        unordered_map<int, int> shift_cnt;

        for (int i = 0; i < n; i++)
        {
            int shift = (t[i] - s[i] + 26) % 26;
            if (shift > 0)
            {
                shift_cnt[shift]++;
            }
        }

        for (auto it : shift_cnt)
        {
            int shift = it.first;
            int cnt = it.second;

            int moves = shift + (cnt - 1) * 26;

            if (moves > k)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}