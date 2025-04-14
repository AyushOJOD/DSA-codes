#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    int lengthAfterTransformations(string s, int t)
    {
        s
            vector<ll>
                letters(26, 0);

        for (char ch : s)
        {
            letters[ch - 'a']++;
        }

        for (int i = 0; i < t; i++)
        {
            vector<ll> temp(26, 0);

            for (int j = 0; j < 26; j++)
            {
                if (j == 25)
                {
                    temp[0] = (temp[0] + letters[j]) % MOD;
                    temp[1] = (temp[1] + letters[j]) % MOD;
                }
                else
                {
                    temp[j + 1] = (temp[j + 1] + letters[j]) % MOD;
                }

                letters = temp;
            }
        }

        int res = 0;

        res = accumulate(begin(letters), end(letters), 0LL);

        return res;
    }
};

int main()
{

    return 0;
}