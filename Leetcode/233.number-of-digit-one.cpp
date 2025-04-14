#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int getOnes(int n)
    {
        string num = to_string(n);
        int cnt = 0;

        for (int i = 0; i < num.length(); i++)
        {
            if (num[i] == '1')
            {
                cnt++;
            }
        }

        return cnt;
    }

public:
    int countDigitOne(int n)
    {

        int val = 0;

        for (int i = 1; i <= n; i++)
        {
            val += getOnes(i);
        }

        return val;
    }
};

int main()
{

    return 0;
}