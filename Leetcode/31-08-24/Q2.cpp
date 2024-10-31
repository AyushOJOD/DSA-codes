#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string stringHash(string s, int k)
    {
        int n = s.length();
        int resLen = n / k;

        string res = "";

        for (int i = 0; i < n; i += k)
        {
            int sum = 0;

            for (int j = i; j < i + k; j++)
            {
                sum += s[j] - 'a';
            }

            int hashedChar = sum % 26;

            res += char(hashedChar + 'a');
        }

        return res;
    }
};

int main()
{

    return 0;
}