#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> prefix(n, 0);

        int curr = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                prefix[i] = 1;
            }
        }
        for (int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i - 1];
        }

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            int zeros = 0, ones = 0;
            for (int j = i; j < n; j++)
            {
                ones = prefix[j];
                if (i != 0)
                    ones -= prefix[i - 1];

                zeros = j - i + 1 - ones;

                if (zeros * zeros > ones)
                {
                    j += ((zeros * zeros) - ones - 1);
                }

                if ((zeros * zeros) <= ones)
                {
                    cnt++;
                }

                if ((zeros * zeros) < ones)
                {
                    int diff = sqrt(ones) - zeros;
                    int nextj = j + diff;

                    if (nextj >= n)
                    {
                        cnt += (n - j - 1);
                    }
                    else
                    {
                        cnt += diff;
                    }
                    j = nextj;
                }
            }
        }
        return cnt;
    }
};

int main()
{

    return 0;
}